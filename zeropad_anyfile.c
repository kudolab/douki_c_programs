
/*
  �ǡ����˥���ͤ�򤹤�ץ����
  
  ������:2002/12/12
  ������:��ƣ����

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "/Users/audio/kenkyu/douki/FileLib_osx.c"

int main(int argc,char *argv[])
{
  int point;
  int length;
  int i;
  double *x;
  
  if(argc < 4){
    fprintf(stderr,"������­��ޤ���\n");
    fprintf(stderr,"this program becomes data tail zero\n");
    fprintf(stderr,"usage: ");
    fprintf(stderr,"zeropad_anyfile point in out\n");
    exit(EXIT_FAILURE);
  }
  
  length = lenfile(argv[2]);
  fprintf(stderr,"length = %d\n",length);
  
  point=atoi(argv[1]);
  if(point>=length){
    fprintf(stderr,"�ǡ�����0�ˤ����ϰϤ���Ŭ�ڤǤ�");
    exit(EXIT_FAILURE);
  }
  
  x = (double *)calloc(length,(size_t)sizeof(double));
  AnyFileRead(argv[2],x,length);
  for (i=point;i<length;i++) x[i]=0.0;
  AnyFileWrite(argv[3],x,length);
  
}
