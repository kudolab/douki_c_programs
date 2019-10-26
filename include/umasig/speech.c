/*
 *  umasig/speech.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/06/28  
 */

/*
 *  lpc analysis
 */

#include <stdlib.h>
#include <stdio.h>
#include "umasig.h"

void auto_correlation(double *r, const double *x, int p, int n) {
    int m, t;
    for (m = 0; m < p; ++m) {
        r[m] = 0.0;
        for (t = 0; t < n - m; ++t)
            r[m] += x[t] * x[t + m];
    }
}

/*
 * 
 * <input> <o> double *k : array pointer (length=p+1)
 *         <o> double *a : array pointer (length=p+1) 
 *         <o> double *r : pointer
 *         <i> const double *v : array pointer (length=p+1)
 *         <i> int p : lpc order
 */
void parcor_and_lpc(double *k, double *a, double *r, const double *v, int p) {
    int i, m;
    double w, u, *ta;

    ta = vec_new(p + 1);

    a[0] = 1.0;
    a[1] = 0.0;
    w = v[1];
    u = v[0];

    m = 1;
    while (1) {
        k[m] = w / u;
        u = u * (1.0 - k[m] * k[m]);

        for (i = 1; i <= m; ++i)
            ta[i] = a[i] - k[m] * a[m - i];
        for (i = 1; i <= m; ++i)
            a[i] = ta[i];
        a[0] = 1.0;

        if (m == p)
            break;

        a[m + 1] = 0.0;

        w = 0.0;
        for (i = 0; i <= m; ++i)
            w += a[i] * v[m + 1 - i];

        ++m;
    }

    *r = u;

    vec_delete(ta);
}






