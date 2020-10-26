#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../../include/FileLib_osx.c"

int main(int argc, char *argv[]) {
    double *dat, *idat, sum, sumx, sumy, sumxx, sumxy, ai, dnsize, a, b;
    long i, j, n;
    char file1[15], file2[15], cndat;

    if (argc < 2) {
        printf(" unbias file1 file2\n");
        exit(-1);
    }

    strcpy(file1, argv[1]);
    strcpy(file2, argv[2]);

    n = lenfile(argv[1]);
    dnsize = (double)n;

    dat = (double *)malloc(sizeof(double) * n);
    idat = (double *)malloc(sizeof(double) * n);

    AnyFileRead(file1, &idat[0], n);

    sum = 0.0;
    for (i = 0; i < n; i++) {
        sum += idat[i];
        dat[i] = sum;
    }
    sum /= (double)n;

    sumx = 0.0;
    sumy = 0.0;
    sumxx = 0.0;
    sumxy = 0.0;
    for (i = 0; i < n; i++) {
        ai = (double)i;
        sumx += ai;
        sumy += dat[i];
        sumxx += ai * ai;
        sumxy += dat[i] * ai;
    }

    a = (sumxy * dnsize - sumx * sumy) / (sumxx * dnsize - sumx * sumx);
    b = (sumxx * sumy - sumx * sumxy) / (sumxx * dnsize - sumx * sumx);

    for (i = 0; i < n; i++) dat[i] = idat[i] - a;

    AnyFileWrite(file2, dat, n);
    return 0;
}
