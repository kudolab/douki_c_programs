/*

	RMS 調整キット (FAT binary 版) fatchdb

	cc -o fatchdb fatchdb.c FileLib.c -lm
	Filelib.c は FAT binary を用いる

	by T.Inada

*/

#include <stdio.h>
/* stdlib.h を include しないと Linux での atof の返り値は不確定になる */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "FileLib_osx.h"


#define LAST_UPDATE "H11.1.25"

int help() {

    fprintf(stderr, "RMS 調整キット (FAT binary 版) fatchdb\n");
    fprintf(stderr, "Last update : %s\n\n", LAST_UPDATE);
    fprintf(stderr, "使用法\n");
    fprintf(stderr, "fatchdb in out [option]\n\n");
    fprintf(stderr, "      in      : 入力ファイル名(.ddb .dda … )\n");
    fprintf(stderr, "      out     : 出力ファイル名(.dsb      … )\n\n");
    fprintf(stderr, "   [option]\n");
    fprintf(stderr, "     -d %%f   : 減衰 (dB)\n");
    fprintf(stderr, "     -u %%f   : 増幅 (dB)\n");
    fprintf(stderr, "     out = 10^(%%f/20)*(in)\n\n");
    fprintf(stderr, "     -a %%f   : 振幅の最大値を %%f にする\n\n");
    exit(1);

}

int main(argc, argv)
        int argc;
        char **argv;
{

    int n, len, file, flag;
    double up, dw, updwdB, updw, maxampl;
    double *data, *odata, maxabs();

    char INname[100], OUTname[100];

    /* Default */
    up = 0.0;
    dw = 0.0;
    maxampl = 1.0;
    n = 0;
    flag = 0;
    file = 0;

    if (argc < 3)
        help();

    while (argc - 1 > n) {
        n++;
        if (argv[n][0] == '-')  /* おぷしょん */
            switch (argv[n][1]) {
                case 'h': /* help モード */
                    help();
                    break;
                case 'd':
                    if (argc > n + 1)
                        dw = atof(argv[n + 1]);
                    n++;
                    flag |= 0x01;
                    break;
                case 'u':
                    if (argc > n + 1)
                        up = atof(argv[n + 1]);
                    n++;
                    flag |= 0x02;
                    break;
                case 'a':
                    if (argc > n + 1)
                        maxampl = atof(argv[n + 1]);
                    n++;
                    flag |= 0x04;
                    break;
                default:
                    fprintf(stderr, "Unknown Option\n\n");
                    help();
            }
        else {
            if (file == 0) {
                strcpy(INname, argv[n]);
                file++;
            } else {
                strcpy(OUTname, argv[n]);
                file++;
            }
        }
    }

    if (flag > 0x04 || maxampl < 0.0)
        help();

    if (file > 1) {
        len = (int) lenfile(INname);
        fprintf(stderr, "入力ファイル = %s\n", INname);
        fprintf(stderr, "出力ファイル = %s\n", OUTname);
        fprintf(stderr, "ファイル長 = %d\n", len);
        data = (double *) malloc(sizeof(double) * len);
        odata = (double *) malloc(sizeof(double) * len);
        AnyFileRead(INname, data, len);
        if (flag < 0x04) {
            updwdB = up - dw;
            updw = pow(10.0, (updwdB / 20.0));
            fprintf(stderr, "増幅率 (dB) : %f\n", updwdB);
        } else {
            fprintf(stderr, "入力の最大振幅は %lf です\n", maxabs(data, len));
            fprintf(stderr, "振幅の最大値を %lf にします\n", maxampl);
            updw = maxampl / maxabs(data, len);
        }
        for (n = 0; n < len; n++)
            odata[n] = updw * data[n];
        AnyFileWrite(OUTname, odata, len);
        free(data);
        free(odata);
    }

}

double maxabs(x, n)
        double *x;
        int n;
{

    double maxabsx;
    int i;

    maxabsx = *x;

    if (n > 1) {
        for (i = 1; i < n; i++)
            maxabsx = (maxabsx > fabs(*(x + i)) ? maxabsx : fabs(*(x + i)));
    }

    return maxabsx;

}
