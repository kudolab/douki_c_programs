#include "umasig.h"
#include <math.h>
#include <time.h>

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)

double ran1(long *idum) {
    int j;
    long k;
    static long iy = 0;
    static long iv[NTAB];
    double temp;

    if (*idum <= 0 || !iy) {
        if (-(*idum) < 1) *idum = 1;
        else *idum = -(*idum);
        for (j = NTAB + 7; j >= 0; j--) {
            k = (*idum) / IQ;
            *idum = IA * (*idum - k * IQ) - IR * k;
            if (*idum < 0) *idum += IM;
            if (j < NTAB) iv[j] = *idum;
        }
        iy = iv[0];
    }
    k = (*idum) / IQ;
    *idum = IA * (*idum - k * IQ) - IR * k;
    if (*idum < 0) *idum += IM;
    j = iy / NDIV;
    iy = iv[j];
    iv[j] = *idum;
    if ((temp = AM * iy) > RNMX) return RNMX;
    else return temp;
}

#undef IA
#undef IM
#undef AM
#undef IQ
#undef IR
#undef NTAB
#undef NDIV
#undef EPS
#undef RNMX

double gasdev(long *idem) {
    double ran1(long *idem);
    static int iset = 0;
    static double gset;
    double fac, rsq, v1, v2;

    if (iset == 0) {
        do {
            v1 = 2.0 * ran1(idem) - 1.0;
            v2 = 2.0 * ran1(idem) - 1.0;
            rsq = v1 * v1 + v2 * v2;
        } while (rsq >= 1.0 || rsq == 0.0);
        fac = sqrt(-2.0 * log(rsq) / rsq);
        gset = v1 * fac;
        iset = 1;
        return v2 * fac;
    } else {
        iset = 0;
        return gset;
    }
}


void uni_random(double *y, int n) {
    double ran1(long *idem);
    long idum;
    int i;
    idum = time(NULL);
    if (idum > 0) idum *= (-1);
    ran1(&idum);
    for (i = 0; i < n; ++i)
        y[i] = ran1(&idum);
}

void gauss_random(double *y, int n) {
    double gasdev(long *idem);
    long idum;
    int i;
    idum = time(NULL);
    if (idum > 0) idum *= (-1);
    gasdev(&idum);
    for (i = 0; i < n; ++i)
        y[i] = gasdev(&idum);

}
