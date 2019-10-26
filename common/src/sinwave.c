#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../../include/FileLib_osx.c"

int main(int argc, char *argv[]) {
    FILE *fpw;
    double *pbuffer;
    int samplingfreq = 48000;
    int sec = 2;
    int filesize = samplingfreq * sec;
    double step = 2.0 * 3.1415926535897 / samplingfreq;
    int i;

    //新規ファイル作成
    fpw = fopen("32bitF_raw.DDB", "wb");
    //失敗
    if (fpw == NULL)
        exit(EXIT_FAILURE);
    //メモリ確保、先頭アドレスをpbuffに入れる
    pbuffer = (double *) malloc(sizeof(double) * filesize);
    //失敗
    if (pbuffer == NULL)
        exit(EXIT_FAILURE);
    //データ作成、メモリ書き込み
    for (i = 0; i < filesize; i++) {
        *(pbuffer + i) = 10000.0 * sin(i * step * 1000);
    }
    //ファイルへ書き込み
    fwrite(pbuffer, sizeof(double), filesize, fpw);
    //ファイルを閉じる
    fclose(fpw);
    //メモリ解放
    free(pbuffer);

    return 0;
}
