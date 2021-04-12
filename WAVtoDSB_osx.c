#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>

typedef struct {
    char fmtId[4];
    int fmtSize;
    short int waveFormatType;
    short int channel;
    int samplesPerSec;
    int bytesPerSec;
    short int blockSize;
    short int bitsPerSample;
} FMTCHUNK;

int read_head(FILE *rFILE, int *freq, int *bitno, int *kind, int *pcmsz, int *pcmstart) {

    char *head;
    FMTCHUNK *fmt;
    int n, chnksz;

    head = malloc(sizeof(char) * 44);

    /* RIFFチャンクである先頭から44byteだけ読み込む */
    if (fread(head, 1, 44, rFILE) != 44) {
        fprintf(stderr, "can't read header. not wav format file.\n");
        exit(EXIT_FAILURE);
    }

    /* WAVファイルかどうかチェック */
    if (strncmp(head, "RIFF", 4) && strncmp(head + 8, "WAVE", 4)) {
        fprintf(stderr, "not wav file.\n");
        exit(EXIT_FAILURE);
    }

    n = 12;

    while (n < 512) {
        if (!strncmp(head + n, "fmt ", 4)) { /* fmtチャンク発見 */
            fmt = (FMTCHUNK *) (head + n);
            n += 4;
            chnksz = *((unsigned int *) (head + n));
            n += 4;
            if (chnksz < 16) { /* fmtチャンクのデータ量が不十分 */
                fprintf(stderr, "not wav file.\n");
                exit(EXIT_FAILURE);
            }
        }
        if (!strncmp(head + n, "data", 4)) {
            n += 4;
            *pcmsz = *((unsigned int *) (head + n));
            n += 4;
            *pcmstart = n;
        }
        ++n;
    }

    fprintf(stdout, "chunk ID:%s\n", fmt->fmtId);
    fprintf(stdout, "chunk size:%d\n", fmt->fmtSize);
    fprintf(stdout, "wave format type:%d\n", fmt->waveFormatType);
    fprintf(stdout, "channel:%d\n", fmt->channel);
    fprintf(stdout, "sample per sec:%d\n", fmt->samplesPerSec);
    fprintf(stdout, "bytes per sec:%d\n", fmt->bytesPerSec);
    fprintf(stdout, "block size:%d\n", fmt->blockSize);
    fprintf(stdout, "bits per sample:%d\n", fmt->bitsPerSample);
    fprintf(stdout, "data size:%d\n", *pcmsz);
    fprintf(stdout, "start position:%d\n", *pcmstart);

    *freq = fmt->samplesPerSec;
    *bitno = fmt->bitsPerSample;
    *kind = fmt->channel;

    return 0;
}


double sinc(double x) {
    double a;
    a = (x == 0) ? 1.0 : sin(x) / x;
    return (a);
}

int main(int argc, char *argv[]) {

    FILE *rFILE, *wFILE_ch1, *wFILE_ch2;

    int freq = 0;                /* サンプリング周波数 */
    int bitno = 0;               /* サンプリングビット数 */
    int kind = 0;                /* データ種別 */
    int pcmsz = 0;               /* PCMデータサイズ */
    int pcmstart = 44;           /* PCMデータ相対開始位置 */

    int i, j, k, len_441, len_480;
    short int *data, *x_441_ch1, *x_441_ch2, buff_ch1, buff_ch2;
    double *x_480_ch1, *x_480_ch2;
    double t, ahe;
    int order = 5; /*総和を取るsincの個数*/

    /* ファイルオープン */
    if ((rFILE = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "can't open file.\n");
        exit(EXIT_FAILURE);
    }

    read_head(rFILE, &freq, &bitno, &kind, &pcmsz, &pcmstart);

    if (kind == 1 && argc != 3) {
        fprintf(stdout, "arguments are incorrect.\n");
        fprintf(stdout, "WAVtoDSB input.wav ch1.DSB\n");
        exit(EXIT_FAILURE);
    }
    if (kind == 2 && argc != 4) {
        fprintf(stdout, "arguments are incorrect.\n");
        fprintf(stderr, "WAVtoDSB input.wav ch1.DSB ch2.DSB\n");
        exit(EXIT_FAILURE);
    }
    if (bitno == 8) {
        fprintf(stdout, "we cannot treat 8bit data.\n");
        exit(EXIT_FAILURE);
    }

    fseek(rFILE, pcmstart, SEEK_SET);   /* ファイルポインタをデータの先頭へ */

    /*
      total_amount_of_data[bytes] = deta_length[samples] * number_of_channels * quantization_level[bytes]
    */

    len_441 = (unsigned int) pcmsz / (kind * bitno / 8);
    len_480 = (int) (48.0 / 44.1 * len_441 + 0.5);
    fprintf(stdout, "data length for 44.1kHz:%d\n", len_441);
    fprintf(stdout, "data length for 48.0kHz:%d\n", len_480);


    if (kind == 1 && bitno == 16 && freq == 48000) { /*モノラルで16ビット*/

        data = malloc(pcmsz);/*モノラルなのでkind=1*/
        fread(data, sizeof(short int), len_480, rFILE);
        x_480_ch1 = (double *) malloc(sizeof(double) * len_480);

        for (i = 0; i < len_480; i++) x_480_ch1[i] = data[i];

        if ((wFILE_ch1 = fopen(argv[2], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < len_480; i++) {
            fprintf(stderr, "%3d [s]", (int) ((double) i / (double) 48000.0));
            buff_ch1 = (short int) (x_480_ch1[i]);
            fwrite(&buff_ch1, sizeof(short int), 1, wFILE_ch1);
            fprintf(stderr, "\b\b\b\b\b\b\b\b\b\b");
        }

    }
    if (kind == 2 && bitno == 16 && freq == 48000) { /*ステレオ,量子化16ビット*/

        data = malloc(pcmsz);/*モノラルなのでkind=1*/
        fread(data, sizeof(short int), len_480 * 2, rFILE);
        x_480_ch1 = (double *) malloc(sizeof(double) * len_480);
        x_480_ch2 = (double *) malloc(sizeof(double) * len_480);

        for (i = 0, j = 0; i < len_441 * 2; i += 2, j++) {
            x_480_ch1[j] = data[i];
            x_480_ch2[j] = data[i + 1];
        }

        if ((wFILE_ch1 = fopen(argv[2], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }
        if ((wFILE_ch2 = fopen(argv[3], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }

        for (i = 0; i < len_480; i++) {
            fprintf(stderr, "%3d [s]", (int) ((double) i / (double) 48000.0));
            buff_ch1 = (short int) (x_480_ch1[i]);
            buff_ch2 = (short int) (x_480_ch2[i]);
            fwrite(&buff_ch1, sizeof(short int), 1, wFILE_ch1);
            fwrite(&buff_ch2, sizeof(short int), 1, wFILE_ch2);
            fprintf(stderr, "\b\b\b\b\b\b\b\b\b\b");
        }

    }
    if (kind == 1 && bitno == 16 && freq == 44100) { /*モノラル,量子化16ビット*/

        data = malloc(pcmsz);/*モノラルなのでkind=1*/
        fread(data, sizeof(short int), len_441, rFILE);
        x_441_ch1 = (short int *) malloc(sizeof(short int) * len_441);
        x_480_ch1 = (double *) malloc(sizeof(double) * len_480);

        for (i = 0; i < len_441; i++) x_441_ch1[i] = data[i];

        if ((wFILE_ch1 = fopen(argv[2], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }

        i = 0;
        x_480_ch1[i] = x_441_ch1[i];
        for (i = 1; i < len_480; i++) {
            fprintf(stderr, "%3d [s]", (int) ((double) i / (double) 48000.0));
            x_480_ch1[i] = 0.0;
            t = (double) i / 48000.0;
            for (k = -order; k <= order; k++) {
                j = (int) ((double) i * 44100.0 / 48000.0 + 0.5) + k;
                ahe = M_PI * 44100.0 * (t - (double) j / 44100.0);
                if (!((j < 0) || (j > len_441))) {
                    x_480_ch1[i] += (double) x_441_ch1[j] * sinc(ahe);
                }
            }
            buff_ch1 = (short int) (x_480_ch1[i] + 0.5);
            fwrite(&buff_ch1, sizeof(short int), 1, wFILE_ch1);
            fprintf(stderr, "\b\b\b\b\b\b\b\b\b\b");
        }
    }
    if (kind == 2 && bitno == 16 && freq == 44100) { /*ステレオで16ビット*/

        data = malloc(pcmsz);/*ステレオなのでkind=2*/
        fread(data, sizeof(short int), len_441 * 2, rFILE);

        x_441_ch1 = (short int *) malloc(sizeof(short int) * len_441);
        x_441_ch2 = (short int *) malloc(sizeof(short int) * len_441);
        x_480_ch1 = (double *) malloc(sizeof(double) * len_480);
        x_480_ch2 = (double *) malloc(sizeof(double) * len_480);

        for (i = 0, j = 0; i < len_441 * 2; i += 2, j++) {
            x_441_ch1[j] = data[i];
            x_441_ch2[j] = data[i + 1];
        }

        if ((wFILE_ch1 = fopen(argv[2], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }
        if ((wFILE_ch2 = fopen(argv[3], "wb")) == NULL) {
            fprintf(stderr, "can't open file.\n");
            exit(EXIT_FAILURE);
        }

        i = 0;
        x_480_ch1[i] = x_441_ch1[i];
        x_480_ch2[i] = x_441_ch2[i];
        for (i = 1; i < len_480; i++) {

            fprintf(stderr, "%3d [s]", (int) ((double) i / (double) 48000.0));
            x_480_ch1[i] = x_480_ch2[i] = 0.0;
            t = (double) i / 48000.0;
            for (k = -order; k <= order; k++) {
                j = (int) ((double) i * 44100.0 / 48000.0 + 0.5) + k;
                ahe = M_PI * 44100.0 * (t - (double) j / 44100.0);
                if (!((j < 0) || (j > len_441))) {
                    x_480_ch1[i] += (double) x_441_ch1[j] * sinc(ahe);
                    x_480_ch2[i] += (double) x_441_ch2[j] * sinc(ahe);
                }
            }

            buff_ch1 = (short int) (x_480_ch1[i] + 0.5);
            buff_ch2 = (short int) (x_480_ch2[i] + 0.5);
            fwrite(&buff_ch1, sizeof(short int), 1, wFILE_ch1);
            fwrite(&buff_ch2, sizeof(short int), 1, wFILE_ch2);
            fprintf(stderr, "\b\b\b\b\b\b\b\b\b\b");
        }


    }

    fclose(rFILE);
    fclose(wFILE_ch1);
    fclose(wFILE_ch2);

}

