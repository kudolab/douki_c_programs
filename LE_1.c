// gcc FC_deviation.c -o FC_deviation 
/* 
   複数の周波数特性データ(*.FFT)から任意の周波数の偏差を算出する

   sh FC_deviation [被験者名] [データ名]

   making by Onodera Yuki at 2001/08/01
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <complex.h>
#pragma jis
//#include "/Users/yuki/kenkyu/douki/FileLib_osx.c"

#define PI 3.141592654
#define SUCCESS 0
#define FAILURE -1

int main(int argc, char *argv[])
{
	int n;			// 読み込みファイル数
	int k;			// カウンタ変数	(**inの行(各サンプルの値)を管理)
	int linecnt;		// 行数カウンタ変数
	int c;			// ファイル読み込みカウンタ変数
	int l;			// 領域確保用カウンタ変数
	int *m;		// 前後誤判定カウンタ 
	int a=0;

	char gomi1[256],gomi2[256];		// 捨てデータ変数
	char name1[256]  = "/ANSWER/answer_KASAHARA_";	// 読み込みファイル名(定数１)
	char name2[256] = ".dat";		// 読み込みファイル
	char NUM[256];				// 読み込みファイル名(変数)
	char name[256];				// 読み込みファイル名
	char name_out[256];			// 書き出しファイル名
	char data_name[256];			// 書き出しファイルの分類名

	int *in_ang;		// 読み込みアングルを保存
	int *in_ans;		// 読み込みアンサーを保存
	double *in_err;	// アングルとアンサーの相対誤差[%]
	double in_ave=0;		// 読み込みファイルの各サンプルにおける平均
	double in_sum=0;		// 読み込みファイルの総和
	FILE *fp_dev;		// 算出した特性偏差の出力ファイルポインタ変数
	FILE *fp_linecnt;	// 読み込みファイルの行数カウント用
	FILE *fp_extra;		// 読み込みファイルのデータ抽出用
	FILE *fp_out;		// 書き出し用ファイルポインタ

	if(argc!=3)
	{
             	fprintf(stderr,"lack of argument!!\n");
                exit(EXIT_FAILURE);
        }
	n = atoi(argv[2]);
	fprintf(stderr,"The data number is %d\n",n);
// --------------------------------------------読み出しファイルの指定------------------------------------------------
	fprintf(stderr,"-------The reading file data-------\n");
		sprintf(NUM,"%d",n);
		strcat(name,argv[1]);
		strcat(name,name1);
		strcat(name,NUM);
		strcat(name,name2);
	// ------------------最初の１周目のみ実行-----ファイル長の長さ・領域の動的確保-------------------------------
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
		   // 読み込みデータの保存領域の動的確保
	// --------------------------------------------データの取り出し--------------------------------------------------
		k=0;
		// 対象ファイルからデータの取り出し(AnyFileReadの代替プログラム)
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
		memset(name,0,sizeof(name));		// 文字列変数nameの初期化
		memset(NUM,0,sizeof(NUM));		// 文字列変数NUMの初期化
// --------------------------------------------前後誤判定、定位誤差の算出--------------------------------------------------------
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
		// in_ansを第一象限に移動。
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
		// in_angを第一象限に移動。
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
// 誤差を計算
		for(k=0;k<linecnt;k++){
		       	in_err[k] = fabs(((double)in_ans[k] - (double)in_ang[k]));
			in_sum = in_sum + in_err[k];
		}
		in_ave = in_sum / linecnt;
//----------------------------------------出力---------------------------------------------
	  a = 0;
		fprintf(stderr,"testNo = %d\n",n);
		for(k=0;k<linecnt;k++){
			a = a +  m[k];
			fprintf(stderr,"  sessionNo %2d  localization ERROR = %4.1lf[deg]   HANTEI = %2d \n",k+1,in_err[k],m[k]);
		}
		fprintf(stderr,      "TEST_AVE_LE = %.1lf[deg]  TEST_HANTEI = %d \n",in_ave,a);
// --------------------------------------------ファイルに書き込み保存---------------------------------------------
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
	memset(data_name,0,sizeof(data_name));		// 文字列変数data_nameの初期化
	memset(name_out,0,sizeof(name_out));		// 文字列変数name_outの初期化

// --------------------------------------------メモリの解放--------------------------------------------------------
	free(in_err);
	free(in_ang);
	free(in_ans);
	free(m);
}
