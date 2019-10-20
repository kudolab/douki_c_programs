// gcc imp_add_by10.c -o imp_add_by10

/* 
   インパルス応答(*.DDA)の総和を算出する(10度毎)

   equ_schroeder [被験者名]

   making by Onodera Yuki at 2016/07/15
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "/Users/yuki/kenkyu/douki/FileLib_osx.c"

int main(int argc, char *argv[])
{
	int a=1;
	int n=0;			// カウンタ
	int i=0;			// カウンタ
	int length=0;			// 信号長
	int num=1;			// カウンタ(スピーカー番号)
	int angle=0;			// カウンタ(角度)
	int completion=0;		// カウンタ(左右判定)

	double *data; 			// 入力データ
	double *out;			// 出力データ(L,R)
	double *out2;			// 出力データ(all)

	char name_in[256];			// 読み込みファイル指定用
	char name_out[256];			// 書き出しファイル指定用
	char name1[256] = "/SSTF/SSTF_";	// 読み込みファイル名(定数１)
	char name2L[256] = "_L.DDA";		// 読み込みファイル名(定数２：L)
	char name2R[256] = "_R.DDA";		// 読み込みファイル名(定数２：R)
	char ANGLE[256];
	char NUM[256];

	FILE *fp_out;			// 出力ファイルポインタ

	if(argc!=2)
	{
		fprintf(stderr,"lack of argument!!\n");
		exit(EXIT_FAILURE);
	}

	for(completion=0;completion<2;completion++)
	{
		for(angle=0;angle<=355;angle=angle+10)
		{
			sprintf(ANGLE,"%d",angle);
			sprintf(NUM,"%d",num);

			strcat(name_in,argv[1]);
			strcat(name_in,name1);
			strcat(name_in,NUM);
			strcat(name_in,"_");
			strcat(name_in,ANGLE);

			if(completion == 0)
				strcat(name_in,name2L);
			else
				strcat(name_in,name2R);

			if (a==1)
			{
				length = lenfile(name_in);
				data = (double *)calloc(length,sizeof(double));
				out = (double *)calloc(length,sizeof(double));
				out2 = (double *)calloc(length,sizeof(double));
				a++;
			}

			AnyFileRead(name_in,data,length);

			// ------------インパルス応答の各サンプルにおける総和を算出------------
			// ------------波形の打ち消しを考慮して、２乗和に加工する--------------
			for(n=0;n<=length;n++)
			{
				out[n] = out[n] + pow(data[n],2.0);
				out2[n] = out2[n] + pow(data[n],2.0);
			}

			memset(ANGLE,0,sizeof(ANGLE));
			memset(NUM,0,sizeof(NUM));
			memset(name_in,0,sizeof(name_in));      // 文字列変数name_inの初期化

			num = num + 2;
			if(num==19)
				num = 1;
		}

		// ------------出力ファイルの作成(L,R)-----------------
		strcat(name_out,argv[1]);
		strcat(name_out,"/SSTF/SSTF_summation");

		if(completion == 0)
			strcat(name_out,name2L);
		else
			strcat(name_out,name2R);

		fp_out=fopen(name_out,"w");
			if(fp_out==NULL)
			{
				fprintf(stderr,"can't write file!!\n");
				exit(EXIT_FAILURE);
			}
			for(i=0;i<=length;i++)
			{
				fprintf(fp_out,"%lf\n",out[i]);
			}
		fclose(fp_out);

		// ------------総和配列の初期化-----------------
		for(n=0;n<=length;n++)
			out[n] = 0.0;

		memset(name_out,0,sizeof(name_out));    // 文字列変数name_outの初期化

		// ------------出力ファイルの作成(all)-----------------
		if(completion == 1)
		{
			strcat(name_out,argv[1]);
			strcat(name_out,"/SSTF/SSTF_summation_all.DDA");

			fp_out=fopen(name_out,"w");
				if(fp_out==NULL)
				{
					fprintf(stderr,"can't write file!!\n");
					exit(EXIT_FAILURE);
				}
				for(i=0;i<=length;i++)
				{
					fprintf(fp_out,"%lf\n",out2[i]);
				}
			fclose(fp_out);
		}
		memset(name_out,0,sizeof(name_out));    // 文字列変数name_outの初期化
	}
	free(data);
	free(out);
	free(out2);
}

