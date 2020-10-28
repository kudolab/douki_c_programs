/* closed_loop.c */
/*  this program finds out rising time of monoaural recording signal under the closed loop codition that A/D and D/A converters are directly connected.*/

// clang closed_loop_new.c -o closed_loop_new /Users/yuki/portaudio/lib/.libs/libportaudio.a -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>
#include "FileLib_osx.h"

/* #define SAMPLE_RATE  (17932) // Test failure to open with this value. */
#define SAMPLE_RATE  (48000)
#define FRAMES_PER_BUFFER (1)
#define INPUT_NUM_CHANNELS  (1)
#define OUTPUT_NUM_CHANNELS (1)
#define NUM_REPETITION  (1)
/* #define DITHER_FLAG     (paDitherOff)  */
#define DITHER_FLAG     (0) /**/

/* @todo Underflow and overflow is disabled until we fix priming of blocking write. */
#define CHECK_OVERFLOW  (0)
#define CHECK_UNDERFLOW  (0)


/* Select sample format. */
#if 0
#define PA_SAMPLE_TYPE  paFloat32
#define SAMPLE_SIZE (4)
#define SAMPLE_SILENCE  (0.0f)
#define CLEAR(a) memset( (a), 0, FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE )
#define PRINTF_S_FORMAT "%.8f"
#elif 1
#define PA_SAMPLE_TYPE  paInt16
#define SAMPLE_SIZE (2)
#define SAMPLE_SILENCE  (0)
#define CLEAR(a) memset( (a), 0,  FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE )
#define PRINTF_S_FORMAT "%d"
#elif 0
#define PA_SAMPLE_TYPE  paInt24
#define SAMPLE_SIZE (3)
#define SAMPLE_SILENCE  (0)
#define CLEAR(a) memset( (a), 0,  FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE )
#define PRINTF_S_FORMAT "%d"
#elif 0
#define PA_SAMPLE_TYPE  paInt8
#define SAMPLE_SIZE (1)
#define SAMPLE_SILENCE  (0)
#define CLEAR(a) memset( (a), 0,  FRAMES_PER_BUFFER * NUM_CHANNELS * SAMPLE_SIZE )
#define PRINTF_S_FORMAT "%d"
#else
#define PA_SAMPLE_TYPE  paUInt8
#define SAMPLE_SIZE (1)
#define SAMPLE_SILENCE  (128)
#define CLEAR( a ) { \
    int i; \
    for( i=0; i<FRAMES_PER_BUFFER*NUM_CHANNELS; i++ ) \
        ((unsigned char *)a)[i] = (SAMPLE_SILENCE); \
}
#define PRINTF_S_FORMAT "%d"
#endif

int n, l, level;


int time_instant_with_max_value(double *x, int N, int *m) {
    int p;
    double max = 0.0;

    for (p = 0; p < N; p++)
        if (x[p] >= max) {
            max = x[p];
            *m = p;
        }
    return 0;
}

int McodeAdamaCreat(char *ifile, double *p) {
    int i, j, k;
    double *m;
    int t[19], ini, id, jd, kd;

    n = 0;
    while (l > (1 << n))
        n++;

    if ((m = (double *) malloc(8 * l)) == NULL)
        exit(EXIT_FAILURE);
    //  Error();
    AnyFileRead(ifile, &m[0], l);

    printf(" Read(%s[%d])\n", ifile, l);
    level = (int) fabs(m[0]);

    for (i = 0; i < l; i++)
        if (m[i] > 0.0) m[i] = 0.0;
        else m[i] = 1.0;
    t[0] = 0;
    L10:;
    ini = t[0];
    for (i = ini + 1; i < l; i++) {
        if (m[i] == 1.0) {
            t[0] = i;
            break;
        }
    }
    for (i = 0; i < n - 1; i++) {
        id = t[i];
        for (j = id + 1; j < l; j++) {
            if ((int) m[j]) {
                for (k = 0; k <= i; k++) {
                    kd = (j + t[k]) % l;
                    if ((int) m[kd]) goto L50;
                }
                t[i + 1] = j;
                goto L40;
            }
            L50:;
        }
        goto L10;
        L40:;
    }
    p[0] = 0;
    for (i = 1; i <= l; i++) {
        id = 0;
        for (j = 0; j < n; j++) {
            jd = (t[j] + i - 1) % l;
            id = id + (int) m[jd] * (1 << j);
        }
        p[id] = (double) i;
    }
    free(m);
    return (0);
}

int McodeAdamaConv(double *p, char *ofile, char *impfile) {
    int i, j, k, m;
    double a, b, is, *x;
    int ix1, ix2, id, jd;
    double *h, coef;

    if ((x = (double *) malloc(8 * (l + 1))) == NULL ||
        (h = (double *) malloc(8 * (l + 1))) == NULL)
        exit(EXIT_FAILURE);

    AnyFileRead(ofile, &x[1], l);

    printf(" Read(%s[%d])\n", ofile, l);
    x[0] = 0.0;
    id = 1;
    for (i = 1; i <= n; i++) {
        jd = id;
        id = id * 2;
        for (k = 0; k <= l; k += id) {
            for (j = 0; j < jd; j++) {
                ix1 = (int) p[k + j];
                ix2 = (int) p[k + j + jd];
                a = x[ix1];
                b = x[ix2];
                x[ix1] = a + b;
                x[ix2] = a - b;
            }
        }
    }
    is = x[0];
    for (i = 1; i <= l; i++) x[i] = x[i] - is;
    coef = 1 / (double) (l + 1);
    h[0] = (double) x[1] * coef;
    h[0] /= (double) level;

    for (i = 1; i < l; i++)
        h[i] = (double) x[l + 1 - i] * coef / (double) level;
    AnyFileWrite(impfile, &h[0], l);
    printf(" Write(%s[%d])\n", impfile, l);
    return (0);
}

/*******************************************************************/
int main(int argc, char *argv[]) {
    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream = NULL;
    PaError err;
    char *sampleBlock;
    int i, j, k, n;
    int numBytes;

    short int *read_buffer;
    short int *write_buffer;
    short int *mcode_data;
    FILE *fp;
    unsigned int len, mcode_len;
    double *rec_data;
    double *madamacode;
    double *mcode_ddata;
    double *imp;
    int attack_point;

    if (argc != 1) {
        fprintf(stderr, "Arguments are not correct.\n");
        fprintf(stderr, "closed_loop\n");
        exit(EXIT_FAILURE);
    }

    fprintf(stderr, "PROGRAM START.\n");
    fflush(stdout);

    write_buffer = (short int *) malloc(sizeof(short int) * FRAMES_PER_BUFFER);
    read_buffer = (short int *) malloc(sizeof(short int) * FRAMES_PER_BUFFER);
    if ((write_buffer == NULL) && (read_buffer == NULL)) exit(-1);


    fprintf(stderr, "Reading mcode data file:%s.\n", "m14.DSB");
    fflush(stdout);

    mcode_len = lenfile("m14.DSB");
    l = mcode_len;
    fprintf(stderr, "mcode length:%d\n", mcode_len);
    mcode_ddata = (double *) malloc(sizeof(double) * mcode_len);
    mcode_data = (short int *) malloc(sizeof(short int) * mcode_len);
    if ((mcode_ddata == NULL) || (mcode_data == NULL)) exit(-1);
    AnyFileRead("m14.DSB", mcode_ddata, mcode_len);
    for (n = 0; n < mcode_len; n++) mcode_data[n] = (short int) mcode_ddata[n];

    /* Set the write_buffer*/
    fp = fopen("rec.DSB", "wb");
    if (fp == NULL) exit(-1);

    fprintf(stderr, "Initializing portaudio...\n");
    fflush(stdout);
    err = Pa_Initialize();
    if (err != paNoError) goto error;

    inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
    inputParameters.channelCount = INPUT_NUM_CHANNELS;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    outputParameters.channelCount = OUTPUT_NUM_CHANNELS;
    outputParameters.sampleFormat = PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    /* -- setup -- */
    fprintf(stderr, "Open the portaudio stream\n");
    fflush(stdout);
    err = Pa_OpenStream(
            &stream,
            &inputParameters,
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff,      /* we won't output out of range samples so don't bother clipping them */
            NULL, /* no callback, use blocking API */
            NULL); /* no callback, so no callback userData */
    if (err != paNoError) goto error;

    fprintf(stderr, "Start the portaudio stream\n");
    fflush(stdout);
    err = Pa_StartStream(stream);
    if (err != paNoError) goto error;

    fprintf(stderr, "Mcode sequences start.\n");
    fflush(stdout);
    j = 0;
    k = 0;
    for (n = 0; n < (int) ((NUM_REPETITION + 2) * mcode_len / FRAMES_PER_BUFFER); n++) {
        for (i = 0; i < FRAMES_PER_BUFFER; i++) {
            if (j == mcode_len) {
                j = 0;
                k++;
            }
            if (k == (NUM_REPETITION + 1)) write_buffer[i] = 0;
            else write_buffer[i] = mcode_data[j++];
        }

        err = Pa_ReadStream(stream, read_buffer, FRAMES_PER_BUFFER);
        if (err && CHECK_OVERFLOW) goto xrun;
        err = Pa_WriteStream(stream, write_buffer, FRAMES_PER_BUFFER);
        if (err && CHECK_UNDERFLOW) goto xrun;

        fwrite(read_buffer, sizeof(short int), FRAMES_PER_BUFFER, fp);
    }

    fclose(fp);

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    len = lenfile("rec.DSB");
    rec_data = (double *) malloc(sizeof(double) * len);
    madamacode = (double *) malloc(sizeof(double) * (mcode_len + 1) * 8);
    AnyFileRead("rec.DSB", rec_data, len);
    AnyFileWrite("rec.DDA", rec_data, len);

    McodeAdamaCreat("m14.DSB", &madamacode[0]);
    McodeAdamaConv(&madamacode[0], "rec.DSB", "tmp.DDA");
    len = lenfile("tmp.DDA");
    imp = (double *) malloc(sizeof(double) * len);
    AnyFileRead("tmp.DDA", imp, len);

    time_instant_with_max_value(imp, len, &attack_point);
    attack_point = attack_point - 40; // Delay the data

    fp = fopen("DOUKI_START", "w");
    if (fp == NULL) exit(-1);
    fprintf(fp, "%d\n", attack_point);
    fprintf(stderr, "attack_point=%d\n", attack_point);
    fprintf(stderr, "File %s was generated.\n", "DOUKI_START");
    fclose(fp);


    free(rec_data);
    free(madamacode);
    free(imp);

    Pa_Terminate();
    return 0;

    xrun:
    if (stream) {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    free(sampleBlock);
    Pa_Terminate();
    if (err & paInputOverflow)
        fprintf(stderr, "Input Overflow.\n");
    if (err & paOutputUnderflow)
        fprintf(stderr, "Output Underflow.\n");
    return -2;

    error:
    if (stream) {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
    free(sampleBlock);
    Pa_Terminate();
    fprintf(stderr, "An error occured while using the portaudio stream\n");
    fprintf(stderr, "Error number: %d\n", err);
    fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
    return -1;
}

