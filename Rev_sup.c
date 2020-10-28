// gcc Rev_sup.c -o Rev_sup 
/* 
   複数の 録音データ(*.DDA)から平均をを算出し、残響成分を取り除く

   Rev_sup  [データ数]

   making by Onodera Yuki at 2001/08/01
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "FileLib_osx.h"

#define PI 3.141592654
#define SUCCESS 0
#define FAILURE -1

int main(int argc, char *argv[]) {
    int n;            // 読み込みファイル数

    int i;            // カウンタ変数 (**inの列(ファイルに対応)を管理)
    int k;            // カウンタ変数	(**inの行(各サンプルの値)を管理)
    int linecnt;        // 行数カウンタ変数
    int c;            // ファイル読み込みカウンタ変数
    int l;            // 領域確保用カウンタ変数
    int completion;        // L→R変更用カウンタ変数

    double tolerance;    // 公差
    int freq_int;        // 周波数(整数型)
    double freq_double;    // 周波数(実数型)

    char name1[256] = "/LSTF/zcLSTF_";    // 読み込みファイル名(定数１)
    char NUM[256];                // 読み込みファイル名(変数)

    char name_out[256];

    double *in;        // 読み込みファイルのデータを保存
    double *in_sum;        // 読み込みファイルの総和
    double *in_ave;        // 読み込みファイルの各サンプルにおける平均
    FILE *fp_out;        // 書き出し用ファイルポインタ
    FILE *fp_in;
    if (argc != 2) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    fprintf(stderr, "The number of data is %d\n", n);
// --------------------------------------------読み出しファイルの指定------------------------------------------------
    fprintf(stderr, "-------The reading file data list-------\n");
    for (i = 1; i <= n; i++) {
        sprintf(NUM, "%d", i);
        strcat(name1, NUM);
        strcat(name1, ".DDA");
        // ------------------最初の１周目のみ実行-----ファイル長の長さ・領域の動的確保-------------------------------
        if (i == 1) {
            linecnt = 0;
            fp_in = fopen(name1, "r");
            if (fp_in) {
                while ((c = getc(fp_in)) != EOF) {
                    if (c == '\n')
                        linecnt++;
                }
                fclose(fp_in);
            }
            fprintf(stderr, "signal length is %d\n", linecnt);
            in_sum = (double *) calloc(linecnt, sizeof(double));        // 総和用変数領域の動的確保
            in_ave = (double *) calloc(linecnt, sizeof(double));        // 平均用変数領域の動的確保
            standard_div = (double *) calloc(linecnt, sizeof(double));    // 標準偏差出力領域の動的確保

            in = (double **) calloc(n + 1, sizeof(double));                     // データ系列
            for (l = 0; l < n + 1; l++)
                in[l] = (double *) calloc(linecnt, sizeof(double));       // サンプル系列

// --------------------------------------------データの取り出し--------------------------------------------------
            // 対象ファイルからデータの取り出し(AnyFileReadの代替プログラム)
            fprintf(stderr, "%s\n", name);
            fp_extra = fopen(name, "r");
            if (fp_in) {
                while ((c = getc(fp_in)) != EOF) {
                    fscanf(fp_in, "%lf", &in[i][k]);
                    k++;
                }
                fclose(fp_in);
            }
            for (k = 0; k < linecnt; k++)                // 各サンプル(k行)におけるの総和を算出
                in_sum[k] = in_sum[k] + in[i][k];
            memset(name, 0, sizeof(name));        // 文字列変数nameの初期化
            memset(NUM, 0, sizeof(NUM));        // 文字列変数NUMの初期化
        }
// --------------------------------------------偏差の導出--------------------------------------------------------
        // 各サンプル列における平均を算出
        for (k = 0; k < linecnt; k++)
            in_ave[k] = in_sum[k] / n;
        // ----------ファイルに書き込み保存(テキスト出力:周波数-偏差特性概要)---------------------------------------------
        strcat(name_out, "/LSTF/ave_czLSTF.DDA");

        fp_out = fopen(name_out, "a+");
        if (fp_out == NULL) {
            fprintf(stderr, "can't write file!!\n");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < linecnt; i++) {
            fprintf(fp_out, "%lf\n", in_ave[i]);
        }
        fclose(fp_out);

        memset(name_out1, 0, sizeof(name_out1));        // 文字列変数name_out1の初期化
        memset(name_out2, 0, sizeof(name_out2));        // 文字列変数name_out2の初期化
// --------------------------------------------メモリの解放--------------------------------------------------------
        free(in);
        free(in_sum);
        free(in_ave);
        free(in_sum_difsquare);
        free(standard_div);
    }

