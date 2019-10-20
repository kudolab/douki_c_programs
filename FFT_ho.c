/* FFT_ho.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "FileLib_osx.c"
#include "/Users/audio/kenkyu/douki/Proctool/fft.c"
#include "/Users/audio/kenkyu/douki/Proctool/ifft.c"

void sampling_hold();

int main(argc,argv)
int  argc;
char *argv[];
{
    char name[2][50];
    
    if(argc>1)
	strcpy(name[0],argv[1]);
    else
    {
	printf("##### Sampling hold - hosei program #####\n");
	printf("Input file name ?");
	scanf("%s",name[0]);
    }
    if(argc>2)
	strcpy(name[1],argv[2]);
    else
    {
	printf("Output file name ?");
        scanf("%s",name[1]);
    }
    sampling_hold(name[0],name[1]);
}

void sampling_hold(name0,name1)
char *name0,*name1;
{
  double *data[4],*hdata[2];
  double pi,hosei;
  int n,i,j,k,len,N,beki;
    
    pi = 4.0*atan(1.0); 
    len = lenfile(name0);
    beki   = (int)(log10((double)len+1)/log10(2.0) + 0.5 + 1);
    N = pow(2,beki);
    fprintf(stderr,"N=%d\n",N);
    for(i=0;i<4;i++)   	
    {
	data[i] = (double *)malloc(sizeof(double)*N);
	hdata[i] = (double *)malloc(sizeof(double)*N);
	if (data[i]==NULL || hdata[i]==NULL) exit(EXIT_FAILURE);
    }

    for(j=0;j<4;j++)	
	for(i=0;i<N;i++)    
	    data[j][i]=0.0;
    
    AnyFileRead(name0,&data[0][0],len);
    fft(data[0],data[1],beki);
  
    hdata[0][0] = 1.0;
    hdata[1][0] = 0.0;
    for(i=1;i<N/2;i++)
    {
	hosei       = pi*(double)i/(double)N;
	hdata[0][i] = (hosei/sin(hosei))*cos(hosei);
	hdata[1][i] = (hosei/sin(hosei))*sin(hosei);
    }
    hdata[1][N/2]=hdata[0][N/2]=0.0;
    for(i=1;i<N/2;i++)
    {
	hdata[0][N/2+i] =   hdata[0][N/2-i];
        hdata[1][N/2+i] = - hdata[1][N/2-i];
    }
    //for (n=0;n<N;n++) fprintf(stdout,"%lf %lf\n",sqrt(20*log10(pow(hdata[0][n],2)+pow(hdata[1][n],2))),atan2(hdata[0][n],hdata[1][n]));
  
    for(i=0;i<N;i++)
    {
	data[2][i] = hdata[0][i]*data[0][i] - hdata[1][i]*data[1][i]; 
	data[3][i] = hdata[1][i]*data[0][i] + hdata[0][i]*data[1][i]; 
    }
    //for (n=0;n<N;n++) fprintf(stdout,"%lf %lf %lf %lf\n",data[0][n],data[1][n],data[2][n],data[3][n]);

    ifft(data[2],data[3],beki);

    for (n=0;n<N;n++) fprintf(stdout,"%lf %lf\n",data[2][n],data[3][n]);

    AnyFileWrite(name1,data[2],len);        
    return ;
}


