#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc,char *argv[]){
  
  int   i,j,range,check,flag;
  int   *matrix;
  char  random_file_name[256];
  FILE  *random_file;
  
  /* main関数への引数渡し */
  if(argc!=2){
    fprintf(stderr,"lack of argument!!\n");
    fprintf(stderr,"Usage:\n upper limit of random number\n");
    exit(EXIT_FAILURE);
  }
  range =  atoi(argv[1]);
 
  sprintf(random_file_name,"random_%d.dat",range);
  random_file = fopen(random_file_name,"w");

  matrix = (int *)calloc(range,sizeof(int));
  if(matrix==NULL)printf("memory reservation error !!");


  srand((unsigned int)time(NULL));
  

  for(i=0;i<=range-1;i++){
    matrix[i] = rand()%range;
    flag = 0;

    while(flag==0){
      check = 0;
      for(j=0;j<=i-1;j++) if(matrix[j]==matrix[i]) check = 1;
      if(check==0)
	flag = 1;
      else matrix[i] = rand()%range;
    }
  }
  

  for(i=0;i<=range-1;i++){
    fprintf(random_file,"%d\n",matrix[i]);
  }

  free(matrix);
  fclose(random_file);
}
