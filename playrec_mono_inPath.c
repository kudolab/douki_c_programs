/* douki_kai.c */

// clang playrec_mono_inPath.c -o playrec_mono_inPath /usr/local/Cellar/portaudio/19.6.0/lib/libportaudio.a -framework CoreAudio -framework AudioToolbox -framework AudioUnit -framework CoreServices

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <portaudio.h>
#include "FileLib_osx.h"

/* #define SAMPLE_RATE  (17932) // Test failure to open with this value. */
#define SAMPLE_RATE  (48000)
#define FRAMES_PER_BUFFER (1)
#define NUM_CHANNELS    (1)
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


/*******************************************************************/
//int main(void);
int main(int argc, char *argv[]) {
    PaStreamParameters inputParameters, outputParameters;
    PaStream *stream = NULL;
    PaError err;
    int j, n;

    short int *read_buffer;
    short int *write_buffer;
    short int *mcode_data;
    FILE *fp;
    int mcode_len;
    double *mcode_ddata;
    int NUM_REPETITION;
    int DOUKI_START;
    char *mfilename;
    short int *read_buffer_all;
    double *rec_raw_data;

    if (argc != 5) {
        fprintf(stderr, "lack of arguments.\n");
        fprintf(stderr, "douki_mono mcode_file(.DSB) douki_num output_filename(.DSB) \n");
        exit(EXIT_FAILURE);
    }
    mfilename = argv[1];
    NUM_REPETITION = atoi(argv[2]);

    fprintf(stderr, "PROGRAM START.\n");
    fflush(stdout);

    write_buffer = (short int *) malloc(sizeof(short int) * FRAMES_PER_BUFFER);
    read_buffer = (short int *) malloc(sizeof(short int) * FRAMES_PER_BUFFER);
    if ((write_buffer == NULL) && (read_buffer == NULL)) exit(-1);


    fprintf(stderr, "Reading mcode data file:%s.\n", "m14.DSB");
    fflush(stdout);

    mcode_len = lenfile(mfilename);
    fprintf(stderr, "mcode length:%d\n", mcode_len);
    mcode_ddata = (double *) malloc(sizeof(double) * mcode_len);
    mcode_data = (short int *) malloc(sizeof(short int) * mcode_len);
    if ((mcode_ddata == NULL) && (mcode_data == NULL)) exit(-1);
    AnyFileRead(mfilename, mcode_ddata, mcode_len);
    for (n = 0; n < mcode_len; n++) mcode_data[n] = (short int) mcode_ddata[n];

    read_buffer_all = (short int *) malloc(sizeof(short int) * (NUM_REPETITION + 5) * mcode_len);
    if (read_buffer_all == NULL)exit(-1);

    /* Set the write_buffer*/
    fp = fopen("tmp.DSB", "wb");
    if (fp == NULL) exit(-1);

    fprintf(stderr, "Initializing portaudio...\n");
    fflush(stdout);
    err = Pa_Initialize();
    if (err != paNoError) goto error;

    inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
    inputParameters.channelCount = NUM_CHANNELS;
    inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = NULL;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    outputParameters.channelCount = NUM_CHANNELS;
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

    fprintf(stderr, "Mcode sequences with %d repetitions start.\n", NUM_REPETITION);
    fflush(stdout);
    j = 0;
    for (n = 0; n < (int) ((NUM_REPETITION + 2) * mcode_len); n++) {
        if (j == mcode_len) {
            j = 0;
        }
        write_buffer[0] = mcode_data[j++];

        err = Pa_ReadStream(stream, read_buffer, FRAMES_PER_BUFFER);
        if (err && CHECK_OVERFLOW) goto xrun;
        err = Pa_WriteStream(stream, write_buffer, FRAMES_PER_BUFFER);
        if (err && CHECK_UNDERFLOW) goto xrun;

        read_buffer_all[n] = read_buffer[0];
        //       fwrite(read_buffer,sizeof(short int),FRAMES_PER_BUFFER,fp);
    }
    fclose(fp);

    err = Pa_StopStream(stream);
    if (err != paNoError) goto error;

    char *filedir = argv[4];
    char *filename = "/DOUKI_START";
    strcat(filedir, filename);
    fp = fopen(filedir, "r");
    if (fp == NULL) exit(EXIT_FAILURE);
    fscanf(fp, "%d\n", &DOUKI_START);
    fclose(fp);

    rec_raw_data = (double *) malloc(sizeof(double) * (NUM_REPETITION + 1) * mcode_len);
    if (rec_raw_data == NULL) exit(EXIT_FAILURE);

//    AnyFileWrite(argv[3],&rec_raw_data[DOUKI_START],len-DOUKI_START);

    for (n = 0; n < ((NUM_REPETITION + 1) * mcode_len); n++) rec_raw_data[n] = (double) read_buffer_all[n];
    AnyFileWrite(argv[3], &rec_raw_data[DOUKI_START], ((NUM_REPETITION + 1) * mcode_len) - DOUKI_START);

    Pa_Terminate();
    return 0;

    xrun:
    if (stream) {
        Pa_AbortStream(stream);
        Pa_CloseStream(stream);
    }
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
    Pa_Terminate();
    fprintf(stderr, "An error occured while using the portaudio stream\n");
    fprintf(stderr, "Error number: %d\n", err);
    fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(err));
    return -1;
}
