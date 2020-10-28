/*
  ��ã���ֺ����θ���������䴰ˡ
  �����ԡ���ƣ���� ��������2004/06/27
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.h"
#include "umasig/umasig.h"

int main(int argc, char *argv[]) {
    int i;
    int length1, length2, length;
    double *x1, *x2, *y, *inpo;
    int fft_points, fft_points_expd, bai;
    double y_max;
    int y_max_i;
    double delay;
    double r;

    if (argc != 5) {
        fprintf(stdout, "lack of arguments \n");
        fprintf(stdout, "linear interpolation taking into acount the Arrival Time Difference\n");
        fprintf(stdout, "Usage:linear_inpo_hrir_using_ATD in1 in2 r out\n");
        exit(EXIT_FAILURE);
    }

    r = atof(argv[3]);
    bai = 32;
    length1 = lenfile(argv[1]);
    length2 = lenfile(argv[2]);
    if (length1 > length2)
        length = length1;
    else
        length = length2;

    fft_points = 1;
    while (fft_points < (length1 + length2 - 1)) fft_points *= 2;
    fft_points_expd = fft_points * bai; /*bai��������Ĺ�򿭤Ф�*/

    fprintf(stdout, "in1:%s length:%d,", argv[1], length1);
    fprintf(stdout, "in2:%s length:%d,", argv[2], length2);
    fprintf(stdout, "FFT:length:%d,", fft_points);
    fprintf(stdout, "bai:%d,", bai);

    x1 = (double *)calloc(length, (size_t)sizeof(double));
    if (1 == NULL) {
        fprintf(stderr, "memory allocation failed at calloc()\n");
        exit(EXIT_FAILURE);
    }
    x2 = (double *)calloc(length, (size_t)sizeof(double));
    if (x2 == NULL) {
        fprintf(stderr, "memory allocation failed at calloc()\n");
        exit(EXIT_FAILURE);
    }
    y = (double *)calloc(fft_points_expd, (size_t)sizeof(double));
    if (y == NULL) {
        fprintf(stderr, "memory allocation failed at calloc()\n");
        exit(EXIT_FAILURE);
    }
    inpo = (double *)calloc(length, (size_t)sizeof(double));
    if (inpo == NULL) {
        fprintf(stderr, "memory allocation failed at calloc()\n");
        exit(EXIT_FAILURE);
    }

    AnyFileRead(argv[1], x1, length1);
    AnyFileRead(argv[2], x2, length2);

    /*compute the normalized cross correlation function*/
    fcorr_normalize(y, x1, x2, length1, length2, fft_points, bai);

    /*detecting the peak of cross correlation function*/
    y_max = 0.0;
    y_max_i = 0;
    for (i = 0; i < fft_points_expd; i++) {
        if (y_max < y[i]) {
            y_max = y[i];
            y_max_i = i;
        }
    }

    /*print the time lag between two impulse responses */
    // delay=(y_max_i-(double)(fft_points*bai/2))/(double)(bai)+1.0;
    delay = ((y_max_i - (double)(length * bai)) / (double)(bai) + 1.0);
    fprintf(stdout, "delay = %lf[sample]\n", delay);

    /*Linear interpolation taking into acount the Arrival Time Difference*/
    fractional_delay_using_linear_phase(x1, length1, fft_points_expd, +delay); /*align the x1 to x2*/
    for (i = 0; i < length; i++) inpo[i] = r * x1[i] + (1 - r) * x2[i];        /*linear interpolation of amplitude*/
    fractional_delay_using_linear_phase(inpo, length, fft_points_expd, -delay * r); /*linear interpolation of ATD*/

    AnyFileWrite(argv[4], inpo, length);
}
