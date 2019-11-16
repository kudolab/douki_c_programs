//gcc make_whitenoise.c -o make_whitenoise -lm -lfftw3

/* 
   白色雑音を生成するプログラム

   作成者:工藤彰洋
   作成日:2006/01/09

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <complex.h>
#include <time.h>

#include <fftw3.h>
//#include <fftw3.h>
#include "../../include/FileLib_osx.c"


int main(int argc, char *argv[]) {

    int k, n;
    int len;
    int range;
    double theta;
    double *x;
    double max;
    fftw_complex *X;
    fftw_plan plan;


    if (argc != 3) {
        fprintf(stderr, "Usage: make_whitenoise signal_length(sample) out(.DXX)\n");
        exit(EXIT_FAILURE);
    }

    srand((unsigned int) time(NULL));

    range = 65536;
    len = atoi(argv[1]);;

    X = (fftw_complex *) fftw_malloc(sizeof(fftw_complex) * len);
    x = malloc(sizeof(double) * len);

    for (k = 0; k < (int) len / 2 + 1; k++) {
        theta = (rand() % range) / (double) range * 2.0 * M_PI;
        X[k][0] = (double) cos(theta);
        X[k][1] = sin(theta);
    }

    for (k = 1; k < (int) len / 2 + 1; k++) {
        theta = (rand() % range) / (double) range * 2.0 * M_PI;
        X[len - k][0] = X[k][0];
        X[len - k][1] = -X[k][1];
    }

    plan = fftw_plan_dft_c2r_1d(len, X, x, FFTW_ESTIMATE);
    fftw_execute(plan);

    for (n = 0; n < len; n++) x[n] /= (double) len;

    max = -100000;
    for (n = 0; n < len; n++)
        if (max < fabs(x[n])) max = fabs(x[n]);
    for (n = 0; n < len; n++) x[n] = x[n] / max * 10000.0;

    AnyFileWrite(argv[2], x, len);

}
