// gcc equ_schroeder3.c -o equ_schroeder3

/* 
   インパルス応答(*.DDA)をシュレーダー関数より残響成分のエネルギー割合を算出する

   equ_schroeder [入力ファイル(.DDA)] [出力ファイル(.txt)]

   making by Onodera Yuki at 2016/07/06
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "FileLib_osx.c"

int main(int argc, char *argv[]) {
    int n = 0;            // カウンタ
    int i = 0;            // カウンタ
    int length = 0;            // 信号長

    double pow_rate = 0.0;        // 要求割合
    double all_pow = 0.0;        // 全エネルギー
    double dust_pow = 0.0;        // 残響エネルギー
    double dust_par = 0.0;        // 残響エネルギー比率

    double *data;            // 入力データ
    double *out;            // 出力データ

    FILE *fp_out;            // 出力ファイルポインタ

    if (argc != 3) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }

    length = lenfile(argv[1]);
    data = (double *) calloc(length, sizeof(double));
    out = (double *) calloc(length, sizeof(double));

    AnyFileRead(argv[1], data, length);

    // ------------信号長全体のエネルギーを算出------------
    for (n = 0; n <= length; n++) {
        all_pow = all_pow + (data[n] * data[n]);
    }
    // ------------エネルギー比率の算出--------------
    for (n = length; n >= 0; n--) {
        dust_pow = dust_pow + (data[n] * data[n]);
        dust_par = dust_pow / all_pow * 100.0;
        out[i] = 100.0 - dust_par;
        i++;
    }

    // ------------出力ファイルの作成-----------------
    fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        fprintf(stderr, "can't write file!!\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i <= length; i++) {
        fprintf(fp_out, "%lf\n", out[i]);
    }

    fclose(fp_out);

    free(data);
    free(out);
}


