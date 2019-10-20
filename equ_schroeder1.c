// gcc equ_schroeder1.c -o equ_schroeder1

/* 
   インパルス応答(*.DDA)のエネルギー割合をシュレーダー関数から算出する

   equ_schroeder [入力ファイル(.DDA)] [切り取り終了点]

   making by Onodera Yuki at 2016/07/01
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "/Users/yuki/kenkyu/douki/FileLib_osx.c"

int main(int argc, char *argv[])
{
	int n=0;				// カウンタ
	int length=0;			// 信号長
	int start=0;			// 切り出し開始点
	int end=0;			// 切り出し終了点

	double all_pow   = 0.0;		// 全エネルギー
	double dust_zero = 0.0;		// 廃棄エネルギー(前半)
	double dust_pow  = 0.0;		// 廃棄エネルギー(総合)
	double dust_par  = 0.0;		// 廃棄エネルギー比率
	double energy_rate  = 0.0;     	// 切り出しエネルギー比率

	double *data; 			// 入力データ

	if(argc!=3)
	{
		fprintf(stderr,"lack of argument!!\n");
		exit(EXIT_FAILURE);
	}

	end = atoi(argv[2]);
	//start = end - 255;

	length = lenfile(argv[1]);
	data = (double *)calloc(length,sizeof(double));

	AnyFileRead(argv[1],data,length);

	// ------------信号長全体のエネルギーを算出------------
	for(n=0;n<=length;n++)
	{
		all_pow = all_pow + (data[n] * data[n]);
	}

	// ------------廃棄領域のエネルギーを算出--------------
	//for(n=0;n<=start;n++)
	//{
	//dust_zero = dust_zero + (data[n] * data[n]);
	//}
	for(n=length;n>=end;n--)
	{
		dust_pow = dust_pow + (data[n] * data[n]);
 	}

	dust_pow = dust_pow + dust_zero;

	// ------------エネルギー比率の算出--------------------
	energy_rate = dust_pow / all_pow * 100.0;
	//energy_rate = 100.0 - dust_par;
	

	//fprintf(stderr,"dust_zero ... %lf\n",dust_zero);
	//fprintf(stderr,"dust_pow ... %lf\n",dust_pow);
	//fprintf(stderr,"dust_par ... %lf\n",dust_par);
	fprintf(stderr,"%lf",energy_rate);

	free(data);
}


