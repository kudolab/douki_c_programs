/*
  2�ĥ���ѥ륹����������إԡ������б�������ֺ������
  �����ԡ���ƣ���� ��������2004/06/21

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.h"
#include "umasig.h"

int main(int argc, char *argv[]) {
    int i, j;
    int length1, length2, length;
    double sampling_freq;
    double *x1, *x2, *y;
    int fft_points, fft_points_expd, bai;
    double y_max;
    int y_max_i;

    complex *X;

    if (argc != 5) {
        fprintf(stderr, "������­��ޤ���\n");
        fprintf(stderr, "output of the time lag corresponding to peak value of cross correlation\n");
        fprintf(stderr, "Usage:calc_ITD sampling_freq[kHz] in_L(.DXX) in_R(.DXX) bai\n");
        exit(EXIT_FAILURE);
    }

    sampling_freq = atof(argv[1]) * 1000.0;
    bai = atoi(argv[4]);
    length1 = lenfile(argv[2]);
    length2 = lenfile(argv[3]);
    length = (length1 - 1) + (length2 - 1);

    fft_points = 1;
    while (fft_points < length) fft_points *= 2;
    fft_points_expd = fft_points * bai;

    fprintf(stderr, "in_L:%s length:%d, ", argv[2], length1);
    fprintf(stderr, "in_R:%s length:%d, ", argv[3], length2);
    fprintf(stderr, "FFT length:%d, ", fft_points);
    fprintf(stderr, "bai :%d\n", bai);

    x1 = (double *)calloc(length1, (size_t)sizeof(double));
    x2 = (double *)calloc(length2, (size_t)sizeof(double));
    y = (double *)calloc(fft_points_expd, (size_t)sizeof(double));
    AnyFileRead(argv[2], x1, length1);
    AnyFileRead(argv[3], x2, length2);

    fcorr_normalize(y, x1, x2, length1, length2, fft_points, bai);
    //  for (i=0;i<fft_points_expd;i++) fprintf(stdout,"%lf\n",y[i]);

    y_max = 0.0;
    y_max_i = 0;
    for (i = 0; i < fft_points_expd; i++) {
        if (y_max < y[i]) {
            y_max = y[i];
            y_max_i = i;
        }
    }

    /*print the time lag between two impulse responses */
    fprintf(stdout, "%lf\n", (y_max_i - (int)(length * bai / 2)) / (sampling_freq * bai));
}
