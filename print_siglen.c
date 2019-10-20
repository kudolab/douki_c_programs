/*
  波形の長さをサンプル単位で出力するプログラム
  作成者：工藤彰洋 作成日：2004/01/06
*/

#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.c"

int main(int argc, char *argv[]) {

    int length;

    if (argc != 2) {
        fprintf(stderr, "lack of arguments.\n");
        fprintf(stderr, "this program print the signal length\n");
        fprintf(stderr, "Usage:print_siglen in\n");
        exit(EXIT_FAILURE);
    }

    length = lenfile(argv[1]);
    fprintf(stdout, "%d\n", length);

}
