// gcc peaking_filter.c -lm -o peaking_filter

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <complex.h>
#include "../../include/FileLib_osx.c"

#define SUCCESS 0
#define FAILURE -1
#define samplerate 48000                    // サンプリング周波数

int main(int argc, char *argv[]) {
    double *input;                        // 入力信号の格納されたバッファ
    double *output;                        // フィルタ処理後の出力信号の格納されたバッファ
    double in1 = 0.0, in2 = 0.0, out1 = 0.0, out2 = 0.0;        // フィルタ計算用のバッファ変数
    double a0 = 0.0, a1 = 0.0, a2 = 0.0, b0 = 0.0, b1 = 0.0, b2 = 0.0;  // フィルタ係数
    double freq;                        // カットオフ周波数
    double q = 0.25;                    // フィルタのQ値（バンド幅を決定する）
    double gain;                        // 増幅量
    int size = 8192;                    // ファイルサイズ指定

    freq = atof(argv[3]);
    gain = atof(argv[4]);

    int length;
    length = lenfile(argv[1]);
    fprintf(stderr, "signal length is %d\n", length);

    input = (double *) calloc(size, (size_t) sizeof(double));
    output = (double *) calloc(size, (size_t) sizeof(double));

    AnyFileRead(argv[1], input, length);

    double omega = 2.0 * 3.14159265 * freq / samplerate;
    double alpha = sin(omega) * sinh(log10(2.0) / 2.0 * q * omega / sin(omega));

    double A = pow(10.0, (gain / 40.0));

    a0 = 1.0 + alpha / A;
    a1 = -2.0 * cos(omega);
    a2 = 1.0 - alpha / A;
    b0 = 1.0 + alpha * A;
    b1 = -2.0 * cos(omega);
    b2 = 1.0 - alpha * A;

    for (int i = 0; i < size; i++) {
        // 入力信号にフィルタを適用、出力信号として書き出し
        output[i] = b0 / a0 * input[i] + b1 / a0 * in1 + b2 / a0 * in2 - a1 / a0 * out1 - a2 / a0 * out2;

        in2 = in1;       // 2つ前の入力信号を更新
        in1 = input[i];    // 1つ前の入力信号を更新

        out2 = out1;       // 2つ前の入力信号を更新
        out1 = output[i];  // 1つ前の入力信号を更新
    }

    AnyFileWrite(argv[2], output, size);
    fprintf(stderr, "> Completed.\n");

    free(input);
    free(output);

}

