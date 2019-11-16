/* 
   FFT output program
  
   making by Kudo Akihiro at 2001/08/01
   editing by Onodera Yuki at 2015/06/22


*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>
#include <fftw3.h>

#include "../../include/FileLib_osx.c"

#define PI 3.141592654
#define SUCCESS 0
#define FAILURE -1

int main(int argc, char *argv[]) {

    int k;
    int length;
    FILE *fp_out;


    double *in;

    fftw_complex *out;
    fftw_plan plan;

    if (argc != 3) {
        fprintf(stderr, "lack of argument!!\n");
        fprintf(stderr, "Usage: fftout in(.DXX) out(2culumns,complex num)\n");
        exit(EXIT_FAILURE);
    }

    length = lenfile(argv[1]);
    fprintf(stderr, "signal length is %d\n", length);

    in = (double *) calloc(length, sizeof(double));
    AnyFileRead(argv[1], in, length);
    out = fftw_malloc(sizeof(fftw_complex) * length);

    plan = fftw_plan_dft_r2c_1d(length, in, out, FFTW_ESTIMATE);
    fftw_execute(plan);

    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        fprintf(stderr, "can't write file!!\n");
        exit(EXIT_FAILURE);
    }

    for (k = 0; k < length; k++) fprintf(fp_out, "%lf %lf\n", creal(out[k]), cimag(out[k]));


    fclose(fp_out);

    fftw_destroy_plan(plan);
    fftw_free(out);
    free(in);

    exit(EXIT_SUCCESS);
}
