/* 二つのバイナリ音声データをLとRに配置し、一つのファイルにまとめるプログラム

   作成日：2001/7/9  作成者：工藤彰洋
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
/*  argv[1]はL信号として配置されるファイル名のポインタ
    argv[2]はR信号として配置されるファイル名のポインタ
*/
{
    int i;
    short int *in1, *in2;
    int in1_len, in2_len;
    FILE *fp1, *fp2, *fp3;
    int hantei;
    char *sp;

    if (argc != 4) {
        fprintf(stderr, "lack of argument!!\n");
        fprintf(stderr, "this program dock L signal and R signal for binary\n");
        fprintf(stderr, "Usage: mono2LR in1 in2 out\n");
        fprintf(stderr, "in1: L signal  in2: R signal\n");
        exit(EXIT_FAILURE);
    }

    /*入力がR信号のみの処理*/
    if (strcmp(argv[1], "non") == 0) {
        if (((fp2 = fopen(argv[2], "rb")) == NULL) || ((fp3 = fopen(argv[3], "wb")) == NULL)) {
            fprintf(stderr, "can't open binary file!!\n");
            exit(EXIT_FAILURE);
        }

        in1 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*L信号のバッファ*/
        if (in1 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }
        in2 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*R信号のバッファ*/
        if (in2 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }

        in1_len = 0;
        fseek(fp2, 0, SEEK_END);
        in2_len = (int)ftell(fp2) / (size_t)sizeof(short int);

        fprintf(stderr, "L signal length is %d\n", in1_len);
        fprintf(stderr, "R signal length is %d\n", in2_len);

        if (in1_len != in2_len) {
            fprintf(stderr, "length of R signal and L signal is defferent!!\n");
            fprintf(stderr, "fill zero to the tail of long singnal.\n");
            if (in1_len < in2_len) in1_len = in2_len;
            fprintf(stderr, "signal length is %d\n", in1_len);
        }

        fseek(fp2, 0, SEEK_SET);
        fseek(fp3, 0, SEEK_SET);

        for (i = 0; i < in1_len; i++) {
            *in1 = (short int)0;
            fwrite(in1, sizeof(short int), 1, fp3);

            if ((fread(in2, sizeof(short int), 1, fp2)) != 1) {
                *in2 = (short int)0;
                fwrite(in2, sizeof(short int), 1, fp3);
            } else
                fwrite(in2, sizeof(short int), 1, fp3);
        }
        fclose(fp2);
        fclose(fp3);
    }
    /*入力がL信号のみの処理*/
    else if (strcmp(argv[2], "non") == 0) {
        if (((fp1 = fopen(argv[1], "rb")) == NULL) || ((fp3 = fopen(argv[3], "wb")) == NULL)) {
            fprintf(stderr, "can't open binary file!!\n");
            exit(EXIT_FAILURE);
        }

        in1 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*L信号のバッファ*/
        if (in1 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }
        in2 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*R信号のバッファ*/
        if (in2 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }

        fseek(fp1, 0, SEEK_END);
        in1_len = (int)ftell(fp1) / (size_t)sizeof(short int);
        in2_len = 0;

        fprintf(stderr, "L signal length is %d\n", in1_len);
        fprintf(stderr, "R signal length is %d\n", in2_len);

        if (in1_len != in2_len) {
            fprintf(stderr, "length of R signal and L signal is defferent!!\n");
            fprintf(stderr, "fill zero to the tail of long singnal.\n");
            if (in1_len < in2_len) in1_len = in2_len;
            fprintf(stderr, "signal length is %d\n", in1_len);
        }

        fseek(fp1, 0, SEEK_SET);
        fseek(fp3, 0, SEEK_SET);

        for (i = 0; i < in1_len; i++) {
            if ((fread(in1, sizeof(short int), 1, fp1)) != 1) {
                *in1 = (short int)0;
                fwrite(in1, sizeof(short int), 1, fp3);
            } else
                fwrite(in1, sizeof(short int), 1, fp3);

            *in2 = (short int)0;
            fwrite(in2, sizeof(short int), 1, fp3);
        }
        fclose(fp1);
        fclose(fp3);
    } else {
        if (((fp1 = fopen(argv[1], "rb")) == NULL) || ((fp2 = fopen(argv[2], "rb")) == NULL) ||
            ((fp3 = fopen(argv[3], "wb")) == NULL)) {
            fprintf(stderr, "can't open binary file!!\n");
            exit(EXIT_FAILURE);
        }

        in1 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*L信号のバッファ*/
        if (in1 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }
        in2 = (short int *)malloc(1 * (size_t)sizeof(short int)); /*R信号のバッファ*/
        if (in2 == NULL) {
            fprintf(stderr, "memory allocation failed at malloc()\n");
            exit(EXIT_FAILURE);
        }

        fseek(fp1, 0, SEEK_END);
        in1_len = (int)ftell(fp1) / (size_t)sizeof(short int);
        fseek(fp2, 0, SEEK_END);
        in2_len = (int)ftell(fp2) / (size_t)sizeof(short int);

        fprintf(stderr, "L signal length is %d\n", in1_len);
        fprintf(stderr, "R signal length is %d\n", in2_len);

        if (in1_len != in2_len) {
            fprintf(stderr, "length of R signal and L signal is defferent!!\n");
            fprintf(stderr, "fill zero to the tail of long singnal.\n");
            if (in1_len < in2_len) in1_len = in2_len;
            fprintf(stderr, "signal length is %d\n", in1_len);
        }

        fseek(fp1, 0, SEEK_SET);
        fseek(fp2, 0, SEEK_SET);
        fseek(fp3, 0, SEEK_SET);

        for (i = 0; i < in1_len; i++) {
            if ((fread(in1, sizeof(short int), 1, fp1)) != 1) {
                *in1 = (short int)0;
                fwrite(in1, sizeof(short int), 1, fp3);
            } else
                fwrite(in1, sizeof(short int), 1, fp3);

            if ((fread(in2, sizeof(short int), 1, fp2)) != 1) {
                *in2 = (short int)0;
                fwrite(in2, sizeof(short int), 1, fp3);
            } else
                fwrite(in2, sizeof(short int), 1, fp3);
        }
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
    }
    exit(EXIT_SUCCESS);
}
