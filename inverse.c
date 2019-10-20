
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#include "FileLib_osx.c"

extern int  Inverse(double *,double *,double *,int);
extern void Levinson(double *a,double *f,double *g,int n);

int help()
{
  printf("inverse: Inverse Filter Estimation\n");
  printf(" Usage: inverse infile infile outfile len\n");
  printf(" argv[1]...IR datafile\n");
  printf(" argv[2]...desire IR datafile\n");
  printf(" argv[3]...output inverse IR datafile\n");
  printf(" argv[4]...tap length(IR datafile)\n");
  printf("\n");
  exit(1);
}
 
int main(int argc,char **argv)
{
  double *dat, *inv, *des;
  int  i,len;

  if(argc!=5)
    help();

  len = atoi(argv[4]);

  dat = (double *)malloc(sizeof(double)*len*4);
  inv = (double *)malloc(sizeof(double)*len*4);
  des = (double *)malloc(sizeof(double)*len*4);
  
  for(i=0;i<len*4;i++) dat[i]=inv[i]=des[i]=0.0;
  
  AnyFileRead(argv[1],dat,len);
  AnyFileRead(argv[2],&des[len],len*2);    
  Inverse(inv,dat,des,len*2);
  AnyFileWrite(argv[3],inv,len*2);	
  
  printf("Done.\n");
}

/*--------------------------------------------*/

int Inverse(double *inv,double *data,double *desire,int len)
{
  
  double *a,*tt,s,sb;
  int j,k;
  
  a = (double *) malloc(sizeof(double)*len);
  tt= (double *) malloc(sizeof(double)*len);
  
  for(j=0;j<len;j++) {
    a[j] = tt[j] = s = sb = 0.0 ;
    for(k=j;k<len;k++)            
	s = s + data[k-j] * data[k];
    a[j]  = s;
    for(k=0;k<len;k++)            
      sb = sb + data[k] * desire[k+j];
    tt[j] = sb;
  }
  Levinson(a,&inv[0],tt,len);
  free(a);    free(tt);
  return len;
}

void Levinson(double *a,double *f,double *g,int n)
{
  double    *t,*temp,alfa,beta,gamma,theta;
  int       i,j;
  
  t    = (double *)malloc(8*n);
  temp = (double *)malloc(8*n);
  
  if( !t || !temp ){
    printf("Allocation Error \n");
    exit(EXIT_FAILURE);
  }
  for(i=0; i<n; i++) f[i]=t[i]=0.0;
  
  alfa=a[0];
  f[0]=g[0]/a[0];
  t[0]=1.0;
  
  for(i=1; i<n; i++){
    beta=gamma=0.0;
    for(j=0; j<=i; j++){
      beta=beta+a[j]*t[i-j];
      gamma=gamma+a[j]*f[i-j];
    }
    for(j=0; j<=i; j++) temp[j]=t[j]/beta-t[i-j]/alfa;
    
    alfa = alfa/beta-beta/alfa;
    theta = (g[i]-gamma)/alfa;
	
    for(j=0; j<=i; j++){
      f[j]=f[j]+theta*temp[i-j];
            t[j]=temp[j];
    }
  }
  free(t);
  free(temp);
}
