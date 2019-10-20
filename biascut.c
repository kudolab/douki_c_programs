#include <stdio.h>
#include <stdlib.h>
#include "FileLib_osx.c"

int main(int argc, char *argv[]) {

    int len, i, m, n;
    int NUM_OF_CHANNELS, amari;
    double point, average;
    double *data_all;

    struct {
        char *fname;
        char tmp[256];
        char *fext;
        char fname_all[256];
        char num[2];
    } moji;

    if (argc != 3) {
        fprintf(stderr, "separate each channel from xch file\n");
        fprintf(stderr, "usage: unbias INFILE_NAME.DXX OUTFILE_NAME.DXX\n");
        exit(EXIT_FAILURE);
    }

//ファイルデータを配列に入れている    
    len = lenfile(argv[1]);
    data_all = (double *) malloc(sizeof(double) * len);
    if (data_all == NULL) {
        fprintf(stderr, "cannot allocate data_all.\n");
        exit(EXIT_FAILURE);
    }
//ファイルの読み込み
    AnyFileRead(argv[1], data_all, len);

    fprintf(stderr, "len = %d\n", len);

    point = 0.0;
    average = 0.0;

    for (i = 0; i < len; i++) {
        point = point + data_all[i];
    }

    average = point / (double) len;
    fprintf(stderr, "average:%lf\n", average);

    for (i = 0; i < len; i++) {
        data_all[i] = data_all[i] - average;
    }

    AnyFileWrite(argv[2], data_all, len);

    exit(EXIT_SUCCESS);
}
