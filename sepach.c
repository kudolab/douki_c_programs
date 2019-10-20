#include <stdio.h>
#include <stdlib.h>
#include "FileLib_osx.c"

int main(int argc,char *argv[]){
  
    int len,monolen,k,m,n;
    int NUM_OF_CHANNELS,amari;
    double *data_all;
    double **data;
    
    struct {
        char *fname;
        char tmp[256];
        char *fext;
        char fname_all[256];
        char num[2];
    } moji;
  
    if(argc!=3){
        fprintf(stderr,"separate each channel from xch file\n");
        fprintf(stderr,"usage: sepach NUM_OF_CHANNELS FILE_NAME.DXX\n");
        exit(EXIT_FAILURE);
    }
    
    len = lenfile(argv[2]);
    data_all = (double *)malloc(sizeof(double)*len);
    if (data_all==NULL){
        fprintf(stderr,"cannot allocate data_all.\n");
        exit(EXIT_FAILURE);
    }
    AnyFileRead(argv[2],data_all,len);
    
    NUM_OF_CHANNELS = atoi(argv[1]);
    amari = len % NUM_OF_CHANNELS;
    fprintf(stderr,"NUM_OF_CHANNELS=%d\n",NUM_OF_CHANNELS);
    if (amari!=0){
        fprintf(stderr,"signal length is not one of the multiples of %d.\n",NUM_OF_CHANNELS);
        exit(EXIT_FAILURE);
    }
    monolen = len / NUM_OF_CHANNELS;
    fprintf(stderr,"length:%d\n",len);
    
    data=(double **)malloc(sizeof(double *)*NUM_OF_CHANNELS);
    
    if (data==NULL){
        fprintf(stderr,"cannot allocate data.\n");
        exit(EXIT_FAILURE);
    }
    for (k=0;k<NUM_OF_CHANNELS;k++) {
        data[k]=(double *)malloc(sizeof(double)*monolen);
        if (data[k]==NULL){
            fprintf(stderr,"cannot allocate data[k].\n");
            exit(EXIT_FAILURE);
        }
    }

    for (k=0;k<NUM_OF_CHANNELS;k++){
        m=0;
        for (n=0;n<len;n=n+NUM_OF_CHANNELS){
            data[k][m] = data_all[n+k];
            m++;
        }
    }
    strcpy(moji.tmp,argv[2]);
    moji.fname = strtok(argv[2],".");

    for (k=0;k<NUM_OF_CHANNELS;k++){

        moji.fext=strstr(moji.tmp,".");
        sprintf(moji.num,"%d",k+1);
        sprintf(moji.fname_all,"%s_%s%s",moji.fname,moji.num,moji.fext);
        fprintf(stderr,"%s\n",moji.fname_all);
        AnyFileWrite(moji.fname_all,data[k],monolen);
    }
    
    
  exit(EXIT_SUCCESS);
}
