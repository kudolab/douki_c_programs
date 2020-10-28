// gcc find_cutpoint.c -o find_cutpoint

/* 
   インパルス応答の２乗総和(SSTF_summation_all.DDA)から切り出し範囲(range:256)を決定する

   equ_schroeder [被験者名]

   making by Onodera Yuki at 2016/07/17
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "FileLib_osx.h"

int main(int argc, char *argv[]) {
    int n = 0;            // カウンタ
    int i = 0;            // カウンタ
    int k = 0;            // カウンタ
    int length = 0;            // 信号長
    int range = 256;            // 切り出し幅(256[sample])

    double threshold = 0.0;        // 閾値
    double average;            // 平均値

    double D_rise = 0.0;        // 直接波...振幅
    int D_sample = 0;        // 直接波...sample値
    double R_rise = 100.0;        // 反射波...振幅
    int R_sample = 0;        // 反射波...sample値
    int count = 0;            // カウンタ
    double cut_point = 100.0;    // 切り出し点...振幅
    int cut_sample;            // 切り出し点...sample値

    double *data;            // 入力データ

    char name_in[256];        // 読み込みファイル指定用

    FILE *fp_out;            // 出力ファイルポインタ

    if (argc != 2) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }

    strcat(name_in, argv[1]);
    strcat(name_in, "/SSTF/SSTF_summation_all.DDA");

    length = lenfile(name_in);
    data = (double *) calloc(length, sizeof(double));

    AnyFileRead(name_in, data, length);

    // ------------閾値の決定...(今回の閾値=入力データの平均値)-------
    for (n = 0; n <= length; n++)
        threshold = threshold + data[n];
    threshold = threshold / length;

    fprintf(stderr, "threshold...%lf\n", threshold);

    for (n = 0; n <= length; n++) {
        average = average + data[n];
        i++;

        if (i == 10) {
            i = 0;
            average = average / 10;

            // 10sample毎に平均を算出し、閾値を超えているか判定(閾値を超える->直接波の立ち上がりがある)
            if (average > threshold) {
                for (k = n - 9; k <= n + 40; k++) {
                    if (D_rise < data[k]) {
                        D_rise = data[k];    // 立ち上がりの振幅を更新
                        D_sample = k;        // 立ち上がりのsample値を更新
                    }
                }
                break;
            }
            average = 0.0;
        }
    }

    fprintf(stderr, "D_rise...%lf\nD_point...%d\n", D_rise, D_sample);

    i = 0;

    for (n = D_sample; n <= length; n++) {
        average = average + data[n];
        i++;

        if (i == 20) {
            i = 0;
            average = average / 20;

            // 20sampleの平均値を順次比較->増加判定を2度(ノイズによる誤動作を防止するため)した辺りに反射波がある
            if (R_rise > average)
                R_rise = average;
            else
                count++;

            if (count == 2) {
                for (k = n - 40; k <= n + 40; k++) {
                    if (R_rise < data[k]) {
                        R_rise = data[k];
                        R_sample = k;
                    }
                }
                break;
            }
            average = 0.0;
        }
    }

    fprintf(stderr, "R_rise...%lf\nR_sample...%d\n", R_rise, R_sample);

    // 移動平均比較により直接波の収束点を検索
    for (n = R_sample - 60; n <= R_sample; n++) {
        average = (data[n - 3] + data[n - 2] + data[n - 1] + data[n] + data[n + 1] + data[n + 2] + data[n + 3]) / 7;

        if (cut_point > average) {
            cut_point = average;
            cut_sample = n;
        }
    }

    fprintf(stderr, "cut_sample...%d\n", cut_sample);

    fp_out = fopen("Cut_END", "w");
    if (fp_out == NULL)
        exit(EXIT_FAILURE);
    fprintf(fp_out, "%d", cut_sample);
    fclose(fp_out);

    fp_out = fopen("Cut_START", "w");
    if (fp_out == NULL)
        exit(EXIT_FAILURE);
    fprintf(fp_out, "%d", cut_sample - 255);
    fclose(fp_out);

    memset(name_in, 0, sizeof(name_in));    // 文字列変数name_outの初期化
    free(data);
}

