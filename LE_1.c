// gcc FC_deviation.c -o FC_deviation 
/* 
   �����̎��g�������f�[�^(*.FFT)����C�ӂ̎��g���̕΍����Z�o����

   sh FC_deviation [�팱�Җ�] [�f�[�^��]

   making by Onodera Yuki at 2001/08/01
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <complex.h>
#pragma jis
//#include "FileLib_osx.c"

#define PI 3.141592654
#define SUCCESS 0
#define FAILURE -1

int main(int argc, char *argv[])
{
	int n;			// �ǂݍ��݃t�@�C����
	int k;			// �J�E���^�ϐ�	(**in�̍s(�e�T���v���̒l)���Ǘ�)
	int linecnt;		// �s���J�E���^�ϐ�
	int c;			// �t�@�C���ǂݍ��݃J�E���^�ϐ�
	int l;			// �̈�m�ۗp�J�E���^�ϐ�
	int *m;		// �O��딻��J�E���^ 
	int a=0;

	char gomi1[256],gomi2[256];		// �̂ăf�[�^�ϐ�
	char name1[256]  = "/ANSWER/answer_KASAHARA_";	// �ǂݍ��݃t�@�C����(�萔�P)
	char name2[256] = ".dat";		// �ǂݍ��݃t�@�C��
	char NUM[256];				// �ǂݍ��݃t�@�C����(�ϐ�)
	char name[256];				// �ǂݍ��݃t�@�C����
	char name_out[256];			// �����o���t�@�C����
	char data_name[256];			// �����o���t�@�C���̕��ޖ�

	int *in_ang;		// �ǂݍ��݃A���O����ۑ�
	int *in_ans;		// �ǂݍ��݃A���T�[��ۑ�
	double *in_err;	// �A���O���ƃA���T�[�̑��Ό덷[%]
	double in_ave=0;		// �ǂݍ��݃t�@�C���̊e�T���v���ɂ����镽��
	double in_sum=0;		// �ǂݍ��݃t�@�C���̑��a
	FILE *fp_dev;		// �Z�o���������΍��̏o�̓t�@�C���|�C���^�ϐ�
	FILE *fp_linecnt;	// �ǂݍ��݃t�@�C���̍s���J�E���g�p
	FILE *fp_extra;		// �ǂݍ��݃t�@�C���̃f�[�^���o�p
	FILE *fp_out;		// �����o���p�t�@�C���|�C���^

	if(argc!=3)
	{
             	fprintf(stderr,"lack of argument!!\n");
                exit(EXIT_FAILURE);
        }
	n = atoi(argv[2]);
	fprintf(stderr,"The data number is %d\n",n);
// --------------------------------------------�ǂݏo���t�@�C���̎w��------------------------------------------------
	fprintf(stderr,"-------The reading file data-------\n");
		sprintf(NUM,"%d",n);
		strcat(name,argv[1]);
		strcat(name,name1);
		strcat(name,NUM);
		strcat(name,name2);
	// ------------------�ŏ��̂P���ڂ̂ݎ��s-----�t�@�C�����̒����E�̈�̓��I�m��-------------------------------
			linecnt = 0;
			fp_linecnt = fopen(name,"r");
			if(fp_linecnt){
				while((c = getc(fp_linecnt)) != EOF){
					if (c =='A'){
						linecnt++;
						fprintf(stderr,"linecnt_OK\n");
					}
				}
			}
			fclose(fp_linecnt);
			fprintf(stderr,"signal length is %d\n",linecnt);
			in_err = (double *)calloc(linecnt,sizeof(double));
			in_ang = (int *)calloc(linecnt,sizeof(int));
			in_ans = (int *)calloc(linecnt,sizeof(int));
			m = (int *)calloc(linecnt,sizeof(int));
		   // �ǂݍ��݃f�[�^�̕ۑ��̈�̓��I�m��
	// --------------------------------------------�f�[�^�̎��o��--------------------------------------------------
		k=0;
		// �Ώۃt�@�C������f�[�^�̎��o��(AnyFileRead�̑�փv���O����)
		fprintf(stderr,"%s\n",name);
		fp_extra = fopen(name,"r");
		if(fp_extra){
			while((c = getc(fp_extra)) != EOF){
				fscanf(fp_extra,"%s %d %s %s %d",gomi1,&in_ang[k],gomi2,&in_ans[k]);					
				fprintf(stderr,"gomi1 = %s  in_ang =  %d  gomi2 =  %s in_ans =  %d\n",gomi1,in_ang[k],gomi2,in_ans[k]);
				k++;
			}
			fclose(fp_extra);
		}
		for(k=0;k<linecnt;k++){
			fprintf(stderr,"gomi1 = %s  in_ang =  %d  gomi2 =  %s in_ans =  %d\n",gomi1,in_ang[k],gomi2,in_ans[k]);
		}
		memset(name,0,sizeof(name));		// ������ϐ�name�̏�����
		memset(NUM,0,sizeof(NUM));		// ������ϐ�NUM�̏�����
// --------------------------------------------�O��딻��A��ʌ덷�̎Z�o--------------------------------------------------------
		for(k=0;k<linecnt;k++){
			if((in_ang[k] == 90)||(in_ang[k] == 270)){
				m[k] = 0;
			}
			else{
				if(((0<=in_ans[k])&&(in_ans[k]<90))||((270<in_ans[k])&&(in_ans[k]<360))){
					if((90<in_ang[k])&&(in_ang[k]<270)){
						m[k] = 1;
					}
				}
				if(((0<=in_ang[k])&&(in_ang[k]<90))||((270<in_ang[k])&&(in_ang[k]<360))){
					if((90<in_ans[k])&&(in_ans[k]<270)){
					 	m[k] = 1;
					}
				}
			}
		}
		for(k=0;k<linecnt;k++){
		// in_ans����ی��Ɉړ��B
			if(in_ans[k]<90){
 				in_ans[k] = in_ans[k];
			}
			else if(in_ans[k]<=180){
				in_ans[k] = (int)(asin(sin((double)in_ans[k]*M_PI/180.0))*180/M_PI);
			}
			/*else if(in_ans[k]<270){
				in_ans[k] = (int)(asin(sin((2*M_PI)-(double)in_ans[k]*M_PI/180.0))*180/M_PI);
			}*/
			else if(in_ans[k]<=360){
				in_ans[k] = (int)(asin(sin((2*M_PI)-(double)in_ans[k]*M_PI/180.0))*180/M_PI);
			}
			if((in_ans[k]%5) != 0){
				in_ans[k] = in_ans[k] + 1;
			}
		// in_ang����ی��Ɉړ��B
			if(in_ang[k]<90){
 				in_ang[k] = in_ang[k];
			}
			else if(in_ang[k]<=180){
				in_ang[k] = (int)(asin(sin((double)in_ang[k]*M_PI/180.0))*180/M_PI);
			}
			/*else if(in_ang[k]<270){
				in_ang[k] = (int)(asin(sin((2*M_PI)-(double)in_ang[k]*M_PI/180.0))*180/M_PI);
			}*/
			else if(in_ang[k]<=360){
				in_ang[k] = (int)(asin(sin((2*M_PI)-(double)in_ang[k]*M_PI/180.0))*180/M_PI);
			}
			if((in_ang[k]%5) != 0){
				in_ang[k] = in_ang[k] + 1;
			}
		}
// �덷���v�Z
		for(k=0;k<linecnt;k++){
		       	in_err[k] = fabs(((double)in_ans[k] - (double)in_ang[k]));
			in_sum = in_sum + in_err[k];
		}
		in_ave = in_sum / linecnt;
//----------------------------------------�o��---------------------------------------------
	  a = 0;
		fprintf(stderr,"testNo = %d\n",n);
		for(k=0;k<linecnt;k++){
			a = a +  m[k];
			fprintf(stderr,"  sessionNo %2d  localization ERROR = %4.1lf[deg]   HANTEI = %2d \n",k+1,in_err[k],m[k]);
		}
		fprintf(stderr,      "TEST_AVE_LE = %.1lf[deg]  TEST_HANTEI = %d \n",in_ave,a);
// --------------------------------------------�t�@�C���ɏ������ݕۑ�---------------------------------------------
	strcat(name_out,argv[1]);
	strcat(name_out,"_ANSWER_localization_error");
	strcat(data_name,argv[1]);
	strcat(data_name,"/ANSWER/answer_***_");
	strcat(data_name,name2);
	fp_out=fopen(name_out,"a+");
	if(fp_out==NULL)
	{
		fprintf(stderr,"can't write file!!\n");
		exit(EXIT_FAILURE);
	}
	fprintf(fp_out,"-------The reading file data-------\n");
	fprintf(fp_out,"-------%s-------\n",data_name);	
		 	fprintf(fp_out,"testNo = %d\n",n);
			for(k=0;k<linecnt;k++){
				a = a + m[k]; 
		   		fprintf(fp_out,"  sessionNo = %2d   localization ERROR = %4.1lf[deg]   HANTEI = %2d \n",k+1,in_err[k],m[k]);
			}
			fprintf(fp_out,      "TEXT_AVE_LE = %.1lf[deg] TEST_HANTEI = %d \n",in_ave,a);
	fclose(fp_out);
	memset(data_name,0,sizeof(data_name));		// ������ϐ�data_name�̏�����
	memset(name_out,0,sizeof(name_out));		// ������ϐ�name_out�̏�����

// --------------------------------------------�������̉��--------------------------------------------------------
	free(in_err);
	free(in_ang);
	free(in_ans);
	free(m);
}
