// gcc FC_deviation_alter.c -o FC_deviation_alter
/* 
   複数の周波数特性データ(*.FFT)から任意の周波数の偏差を算出する
   (逆特性のM系列信号を用いた際に適用するプログラム)
   FC_deviation_alter [被験者名] [データ数]

   making by Onodera Yuki at 2001/08/01
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>

#include "FileLib_osx.c"

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

    double gomi1, gomi2;    // 捨てデータ変数
    int gomi3;        // 捨てデータ変数

    double tolerance;    // 公差
    int freq_int;        // 周波数(整数型)
    double freq_double;    // 周波数(実数型)

    char name1[256] = "/iECTF/ciECTF_";    // 読み込みファイル名(定数１)
    char name2L[256] = "_L.FFT";        // 読み込みファイル名(定数２：L)
    char name2R[256] = "_R.FFT";        // 読み込みファイル名(定数２：R)
    char NUM[256];                // 読み込みファイル名(変数)
    char name[256];                // 読み込みファイル名

    char name_out1[256];            // 書き出しファイル名１
    char name_out2[256];            // 書き出しファイル名２
    char data_name[256];            // 書き出しファイルの分類名

    double **in;        // 読み込みファイルのデータを保存
    double *in_sum;        // 読み込みファイルの総和
    double *in_ave;        // 読み込みファイルの各サンプルにおける平均
    double *in_sum_difsquare;// 二乗誤差の総和
    double *standard_div;    // 標準偏差の出力変数
    FILE *fp_dev;        // 算出した特性偏差の出力ファイルポインタ変数
    FILE *fp_linecnt;    // 読み込みファイルの行数カウント用
    FILE *fp_extra;        // 読み込みファイルのデータ抽出用
    FILE *fp_out;        // 書き出し用ファイルポインタ

    if (argc != 3) {
        fprintf(stderr, "lack of argument!!\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[2]);
    fprintf(stderr, "The number of data is %d\n", n);
// --------------------------------------------読み出しファイルの指定------------------------------------------------
    for (completion = 0; completion < 2; completion++) {
        fprintf(stderr, "-------The reading file data list-------\n");
        for (i = 1; i <= n; i++) {
            sprintf(NUM, "%d", i);
            strcat(name, argv[1]);
            strcat(name, name1);
            strcat(name, NUM);
            // -----------------completion==0ならばLのファイルを読み取り、1ならばRを読み取る-----------------------------
            if (completion == 0)
                strcat(name, name2L);
            else
                strcat(name, name2R);
            // ------------------最初の１周目のみ実行-----ファイル長の長さ・領域の動的確保-------------------------------
            if (i == 1) {
                linecnt = 0;
                fp_linecnt = fopen(name, "r");
                if (fp_linecnt) {
                    while ((c = getc(fp_linecnt)) != EOF) {
                        if (c == '\n')
                            linecnt++;
                    }
                    fclose(fp_linecnt);
                }
                fprintf(stderr, "signal length is %d\n", linecnt);
                in_sum = (double *) calloc(linecnt, sizeof(double));        // 総和用変数領域の動的確保
                in_ave = (double *) calloc(linecnt, sizeof(double));        // 平均用変数領域の動的確保
                in_sum_difsquare = (double *) calloc(linecnt, sizeof(double));    // 二乗誤差平均領域の動的確保
                standard_div = (double *) calloc(linecnt, sizeof(double));    // 標準偏差出力領域の動的確保
                // 読み込みデータの保存領域の動的確保
                in = (double **) calloc(n + 1, sizeof(double));                // データ系列
                for (l = 0; l < n + 1; l++)
                    in[l] = (double *) calloc(linecnt, sizeof(double));    // サンプル系列
            }
// --------------------------------------------データの取り出し--------------------------------------------------
            k = 0;
            // 対象ファイルからデータの取り出し(AnyFileReadの代替プログラム)
            fprintf(stderr, "%s\n", name);
            fp_extra = fopen(name, "r");
            if (fp_extra) {
                while ((c = getc(fp_extra)) != EOF) {
                    fscanf(fp_extra, "%lf %lf %lf %d", &gomi1, &gomi2, &in[i][k], &gomi3);

                    if (in[i][k] <= -120.0)        // 値が無限大(-inf)の場合は-120.0に上書き
                        in[i][k] = -120.0;
                    k++;
                }
                fclose(fp_extra);
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
        // 各サンプル列と取得データとの差分計算→二乗計算→各サンプル列毎の結果の総和を算出
        for (i = 1; i <= n; i++) {
            for (k = 0; k < linecnt; k++) {
                in[i][k] = in[i][k] - in_ave[k];
                in[i][k] = pow(in[i][k], 2.0);
                in_sum_difsquare[k] = in_sum_difsquare[k] + in[i][k];
            }
        }
        // 二乗の総和の平均を計算→ルートでくくる(＝標準偏差)
        for (k = 0; k < linecnt; k++) {
            in_sum_difsquare[k] = in_sum_difsquare[k] / i;
            standard_div[k] = sqrt(in_sum_difsquare[k]);
        }
        // --------------------------------------------周波数ごとに偏差を出力---------------------------------------------
        for (i = 0; i <= 24; i++) {
            tolerance = linecnt / 48;
            freq_int = (int) i * tolerance;
            fprintf(stderr, "sampleNo = %d	周波数%d[kHz]	偏差%.2lf\n", freq_int, i, standard_div[freq_int]);
        }
        // ----------ファイルに書き込み保存(テキスト出力:周波数-偏差特性概要)---------------------------------------------
        strcat(name_out1, argv[1]);
        strcat(name_out1, "_iECTF_standard_diviation");

        strcat(data_name, argv[1]);
        strcat(data_name, "/iECTF/ciECTF_***_");
        if (completion == 0)
            strcat(data_name, name2L);
        else
            strcat(data_name, name2R);

        fp_out = fopen(name_out1, "a+");
        if (fp_out == NULL) {
            fprintf(stderr, "can't write file!!\n");
            exit(EXIT_FAILURE);
        }
        fprintf(fp_out, "-------The reading file data-------\n");
        fprintf(fp_out, "-------%s-------\n", data_name);
        for (i = 0; i <= 24; i++) {
            freq_int = (int) i * tolerance;
            fprintf(fp_out, "sampleNo = %d	周波数%d[kHz]	偏差%.2lf\n", freq_int, i, standard_div[freq_int]);
        }
        fclose(fp_out);

        // ----------------ファイルに書き込み保存(グラフ出力:周波数-偏差特性)---------------------------------------------
        strcat(name_out2, argv[1]);
        if (completion == 0)
            strcat(name_out2, "_iECTF_div_character_L.txt");
        else
            strcat(name_out2, "_iECTF_div_character_R.txt");

        fp_out = fopen(name_out2, "a+");
        if (fp_out == NULL) {
            fprintf(stderr, "can't write file!!\n");
            exit(EXIT_FAILURE);
        }
        for (k = 0; k <= linecnt; k++) {
            freq_double = (double) k / linecnt * 48;

            fprintf(fp_out, "%lf %.2lf\n", freq_double, standard_div[k]);
        }
        fclose(fp_out);

        for (k = 0; k < linecnt; k++)                // 総和配列の初期化
        {
            in_sum[k] = 0;
            in_sum_difsquare[k] = 0;
        }

        memset(data_name, 0, sizeof(data_name));        // 文字列変数data_nameの初期化
        memset(name_out1, 0, sizeof(name_out1));        // 文字列変数name_out1の初期化
        memset(name_out2, 0, sizeof(name_out2));        // 文字列変数name_out2の初期化
    }
// --------------------------------------------メモリの解放--------------------------------------------------------
    free(in);
    free(in_sum);
    free(in_ave);
    free(in_sum_difsquare);
    free(standard_div);
}

