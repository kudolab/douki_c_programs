// gcc equ_schroeder2.c -o equ_schroeder2

/* 
   インパルス応答(*.DDA)を指定したエネルギー割合を元にシュレーダー関数より切り出す

   equ_schroeder [入力ファイル(.DDA)] [切り出しエネルギー割合]

   making by Onodera Yuki at 2016/07/01
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "FileLib_osx.c"

int main(int argc, char *argv[]) {
    int n = 0;            // カウンタ
    int length = 0;            // 信号長
    int start = 0;            // 切り出し開始点
    int end = 0;            // 切り出し終了点

    double pow_rate = 0.0;        // 要求割合
    double all_pow = 0.0;        // 全エネルギー
    double dust_pow = 0.0;        // 廃棄エネルギー
    double dust_par = 0.0;        // 廃棄エネルギー比率
    double main_par = 0.0;        // 切り出しエネルギー比率

    double *data;            // 入力データ

    if (argc != 3) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }

    pow_rate = atof(argv[2]);

    length = lenfile(argv[1]);
    data = (double *) calloc(length, sizeof(double));

    AnyFileRead(argv[1], data, length);

    // ------------信号長全体のエネルギーを算出------------
    for (n = 0; n <= length; n++) {
        all_pow = all_pow + (data[n] * data[n]);
    }
    // ------------切り出し終了点を算出--------------
    for (n = length; n >= 0; n--) {
        dust_pow = dust_pow + (data[n] * data[n]);
        dust_par = dust_pow / all_pow * 100.0;
        main_par = 100.0 - dust_par;

        if (dust_par > pow_rate) {
            end = n;
            //start = end - 255;
            break;
        }
    }
    //	fprintf(stderr,"start ... %d\n",start);
    fprintf(stderr, "end ... %d\n", end);

    free(data);
}


