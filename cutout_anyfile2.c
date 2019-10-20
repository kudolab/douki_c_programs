// gcc cutout_anyfile2.c -o cutout_anyfile2

/*
  Program to cut and bring down a wave pattern and to cut and bring down the file of any form
  making by Kudo Akihiro at 2001/09/11
  editing by Onodera Yuki at 2016/07/19

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "/Users/audio/kenkyu/douki/FileLib_osx.c"

int main(int argc,char *argv[])
{
  
	FILE *fp_in;
	FILE *fp_out;
	FILE *fp_point;
  int i,j;
  int length;
  int st_point;
  int width;
  int end_point;
  double *x;

  if(argc!=3){
    fprintf(stderr,"An argument is insufficient\n");
    fprintf(stderr,"this program cut out signal\n");
    fprintf(stderr,"Usage:  cutout in start end out\n");
    exit(EXIT_FAILURE);
  }
  length=lenfile(argv[1]);

	fp_point=fopen("Cut_START","r");
	if (fp_point==NULL)
		exit(EXIT_FAILURE);
	fscanf(fp_point,"%d\n",&st_point);
	fclose(fp_point);

	fp_point=fopen("Cut_END","r");
	if (fp_point==NULL)
		exit(EXIT_FAILURE);
	fscanf(fp_point,"%d\n",&end_point);
	fclose(fp_point);

	fprintf(stderr,"st_point...%d\nend_point...%d\n",st_point,end_point);

  width = end_point-(st_point-1);
  fprintf(stderr,"signal:%s, length is %d --> %d\n",argv[1],length,width);
  x=(double *)calloc(length,sizeof(double));
  AnyFileRead(argv[1],x,length);
  AnyFileWrite(argv[4],&x[st_point-1],width);

}
