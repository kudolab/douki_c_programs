/*********************************************
    IMPmcode
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "FileLib_osx.c"

int level, n, l;

int Error() {
    printf("Allocation error\n");
    exit(-1);
}

int McodeAdamaCreat(char *ifile, double *p) {
    int i, j, k;
    double *m;
    int t[19], ini, id, jd, kd;

    n = 0;
    while (l > (1 << n))
        n++;

    if ((m = (double *) malloc(8 * l)) == NULL)
        Error();
    AnyFileRead(ifile, &m[0], l);

    printf(" Read(%s[%d])\n", ifile, l);
    level = (int) fabs(m[0]);

    for (i = 0; i < l; i++)
        if (m[i] > 0.0) m[i] = 0.0;
        else m[i] = 1.0;
    t[0] = 0;
    L10:;
    ini = t[0];
    for (i = ini + 1; i < l; i++) {
        if (m[i] == 1.0) {
            t[0] = i;
            break;
        }
    }
    for (i = 0; i < n - 1; i++) {
        id = t[i];
        for (j = id + 1; j < l; j++) {
            if ((int) m[j]) {
                for (k = 0; k <= i; k++) {
                    kd = (j + t[k]) % l;
                    if ((int) m[kd]) goto L50;
                }
                t[i + 1] = j;
                goto L40;
            }
            L50:;
        }
        goto L10;
        L40:;
    }
    p[0] = 0;
    for (i = 1; i <= l; i++) {
        id = 0;
        for (j = 0; j < n; j++) {
            jd = (t[j] + i - 1) % l;
            id = id + (int) m[jd] * (1 << j);
        }
        p[id] = (double) i;
    }
    free(m);
    return (0);
}

int McodeAdamaConv(double *p, char *ofile, char *impfile) {
    int i, j, k, m;
    double a, b, is, *x;
    int ix1, ix2, id, jd;
    double *h, coef;

    if ((x = (double *) malloc(8 * (l + 1))) == NULL ||
        (h = (double *) malloc(8 * (l + 1))) == NULL)
        Error();

    AnyFileRead(ofile, &x[1], l);

    printf(" Read(%s[%d])\n", ofile, l);
    x[0] = 0.0;
    id = 1;
    for (i = 1; i <= n; i++) {
        jd = id;
        id = id * 2;
        for (k = 0; k <= l; k += id) {
            for (j = 0; j < jd; j++) {
                ix1 = (int) p[k + j];
                ix2 = (int) p[k + j + jd];
                a = x[ix1];
                b = x[ix2];
                x[ix1] = a + b;
                x[ix2] = a - b;
            }
        }
    }
    is = x[0];
    for (i = 1; i <= l; i++) x[i] = x[i] - is;
    coef = 1 / (double) (l + 1);
    h[0] = (double) x[1] * coef;
    h[0] /= (double) level;

    for (i = 1; i < l; i++)
        h[i] = (double) x[l + 1 - i] * coef / (double) level;
    AnyFileWrite(impfile, &h[0], l);
    printf(" Write(%s[%d])\n", impfile, l);
    return (0);
}


int main(int argc, char **argv) {
    double *madamacode;

    printf("###### IMPmcode ######\n");
    if (argc < 4) {
        printf("IMPmcode inputfile outputfile impulsefile\n");
        exit(-1);
    }

    l = lenfile(argv[1]); //read .DSB file for mcode sequence.
    if ((madamacode = (double *) malloc(8 * (l + 1))) == NULL) Error();
    printf("    AdamaCreat \n");
    McodeAdamaCreat(argv[1], &madamacode[0]);
    AnyFileWrite("amdama.DDA", madamacode, l + 1);
    printf("    Convolution \n");
    McodeAdamaConv(&madamacode[0], argv[2], argv[3]);

    printf("######## Done ########\n");

}

