/*
  multiply start of signal and end by cosine_window
  making by Kudo Akihiro at 2004/08/18
  editing by Onodera Yuki at 2015/06/18
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/FileLib_osx.c"

#define PI 3.141592654

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    int i, j;
    double *x;
    int length;
    double sampling_freq;
    int start_point;
    int width;
    int end_point;
    int window_len;

    if (argc != 6) {
        fprintf(stderr, "An argument is insufficient\n");
        fprintf(stderr, "this program wights a start and end part of the signal with consine window\n");
        fprintf(stderr, "Usage: cosine_windowing in sampling_freq[kHz] start window_length[ms] out\n");
        exit(EXIT_FAILURE);
    }
    length = lenfile(argv[1]);
    sampling_freq = atof(argv[2]);
    start_point = atoi(argv[3]);
    window_len = (int)(atof(argv[4]) * sampling_freq);

    fprintf(stderr, "signal:%s \nsignal length:%d ,window length:%d[sample]\n", argv[1], length, window_len);
    x = (double *)calloc(length, sizeof(double));
    AnyFileRead(argv[1], x, length);

    i = start_point;
    for (; i < start_point + window_len; i++) x[i] = x[i] * sin((double)(i - start_point) / window_len * PI / 2.0);

    i = length - window_len;
    for (; i < length; i++) x[i] = x[i] * cos((double)(i - (length - window_len)) / window_len * PI / 2.0);

    AnyFileWrite(argv[5], x, length);
    free(x);
}
