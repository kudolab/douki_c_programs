// gcc fftout4.c -o fftout4 -lm /usr/local/lib/libfftw3.a 

/* 
   FFT output program
  
   making by Kudo Akihiro at 2001/08/01
   editing by Onodera Yuki at 2016/04/01
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>
#include "include/fftw3.h"

#include "FileLib_osx.c"

#define PI 3.141592654
#define SUCCESS 0
#define FAILURE -1

int main(int argc,char *argv[])
{
	int k;
	int length;
	int num;
	FILE *fp_out;
	double *in;
	double fftout;

	fftw_complex *out;
	fftw_plan plan;

	if(argc!=4)
	{
		fprintf(stderr,"lack of argument!!\n");
		exit(EXIT_FAILURE);
	}

	length = lenfile(argv[1]);
	fprintf(stderr,"signal length is %d\n",length);
	num = atoi(argv[3]);

	in = (double *)calloc(length,sizeof(double));
	AnyFileRead(argv[1],in,length);
	out = fftw_malloc(sizeof(fftw_complex)*length);

	plan=fftw_plan_dft_r2c_1d(length,in,out,FFTW_ESTIMATE);
	fftw_execute(plan);

	fp_out=fopen(argv[2],"w");
	if(fp_out==NULL)
	{
		fprintf(stderr,"can't write file!!\n");
		exit(EXIT_FAILURE);
	}

	for(k=0;k<length;k++)
	{
		fftout = 20.0*log10(sqrt(creal(out[k])*creal(out[k])+cimag(out[k])*cimag(out[k])));
		fprintf(fp_out,"%lf %lf %lf %d \n",creal(out[k]),cimag(out[k]),fftout,num);
	}

	fclose(fp_out);

	fftw_destroy_plan(plan);
	fftw_free(out);
	free(in);

	exit(EXIT_SUCCESS);
}
