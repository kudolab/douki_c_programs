// gcc equ_schroeder4.c -o equ_schroeder4

/* 
   インパルス応答(*.DDA)をシュレーダー関数より残響成分のエネルギー割合db表記でを一括で算出する
   インパルス応答との対応改善

   equ_schroeder [被験者名]

   making by Onodera Yuki at 2016/07/13
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
    int length = 0;            // 信号長
    int num = 1;            // カウンタ(スピーカー番号)
    int angle = 0;            // カウンタ(角度)
    int completion = 0;        // カウンタ(左右判定)

    double all_pow = 0.0;        // 全エネルギー
    double dust_pow = 0.0;        // 残響エネルギー
    double dust_par = 0.0;        // 残響エネルギー比率

    double *data;            // 入力データ
    double *out;            // 出力データ

    char name_in[256];            // 読み込みファイル指定用
    char name_out[256];            // 書き出しファイル指定用
    char name1[256] = "/SSTF/SSTF_";    // 読み込みファイル名(定数１)
    char name2L[256] = "_L.DDA";        // 読み込みファイル名(定数２：L)
    char name2R[256] = "_R.DDA";        // 読み込みファイル名(定数２：R)
    char ANGLE[256];
    char NUM[256];

    FILE *fp_out;            // 出力ファイルポインタ

    if (argc != 2) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }

    for (angle = 0; angle <= 355; angle = angle + 5) {
        for (completion = 0; completion < 2; completion++) {
            sprintf(ANGLE, "%d", angle);
            sprintf(NUM, "%d", num);

            strcat(name_in, argv[1]);
            strcat(name_in, name1);
            strcat(name_in, NUM);
            strcat(name_in, "_");
            strcat(name_in, ANGLE);

            if (completion == 0)
                strcat(name_in, name2L);
            else
                strcat(name_in, name2R);

            length = lenfile(name_in);
            data = (double *) calloc(length, sizeof(double));
            out = (double *) calloc(length, sizeof(double));

            AnyFileRead(name_in, data, length);

            // ------------信号長全体のエネルギーを算出------------
            for (n = 0; n <= 4192; n++) {
                all_pow = all_pow + (data[n] * data[n]);
            }

            // ------------エネルギー比率の算出--------------
            for (n = 4192; n >= 0; n--) {
                dust_pow = dust_pow + (data[n] * data[n]);
                dust_par = dust_pow / all_pow;
                out[n] = 1.0 - dust_par;
                // -------------エネルギー比率をデシベル表記-----------
//				out[n] = 10 * log10(out[i]);
            }

            // ------------出力ファイルの作成-----------------
            strcat(name_out, argv[1]);
            strcat(name_out, "/Energy_rate/output_");
            strcat(name_out, ANGLE);

            if (completion == 0)
                strcat(name_out, name2L);
            else
                strcat(name_out, name2R);

            fp_out = fopen(name_out, "w");
            if (fp_out == NULL) {
                fprintf(stderr, "can't write file!!\n");
                exit(EXIT_FAILURE);
            }
            for (i = 0; i <= length; i++) {
                fprintf(fp_out, "%lf\n", out[i]);
            }
            fclose(fp_out);

            fprintf(stderr, "input -------> %s\n", name_in);
            fprintf(stderr, "output-------> %s\n", name_out);

            all_pow = 0.0;
            dust_pow = 0.0;
            dust_par = 0.0;

            i = 0;
            memset(ANGLE, 0, sizeof(ANGLE));
            memset(NUM, 0, sizeof(NUM));
            memset(name_in, 0, sizeof(name_in));    // 文字列変数name_inの初期化
            memset(name_out, 0, sizeof(name_out));    // 文字列変数name_outの初期化
        }
        num = num + 1;
        if (num == 19)
            num = 1;
    }
    free(data);
    free(out);
}


