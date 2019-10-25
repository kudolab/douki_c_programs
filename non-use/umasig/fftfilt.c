/*
   FFT-based FIR filtering using overlap-add method.

   Auther: Takahiro Umayahara
   2001/04/28
 */
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>
#include "/usr/local/include/fftw3.h"
#include "umasig.h"

/*
   Next power of two.
   p = nextpow2(A) returns the smallest power of two 
   that is greater than or equal to the absolute value of A. 
   (That is, p that satisfies 2^p >= abs(A)).
*/
int nextpow2(int A) {
    int p = 0, aa = abs(A);
    unsigned long pp = 1;

    do {
        ++p;
        pp *= 2;
    } while (pp < aa);

    return p;
}

static void hc_vec_mul(double *vec_a, const double *vec_b, int n) {
    int i;
    for (i = 1; i < n / 2; ++i) {
        complex a, b, c;
        a.re = vec_a[i];
        a.im = vec_a[n - i];
        b.re = vec_b[i];
        b.im = vec_b[n - i];
        c = c_mul(a, b);
        vec_a[i] = c.re;
        vec_a[n - i] = c.im;
    }
    vec_a[0] *= vec_b[0];
    vec_a[n / 2] *= vec_b[n / 2];
}

/* 
   Length of y is n_b + n_x - 1.
   You can specify the fft length by argument n.
   If you set n = 0, fftfilt will determine the fft length automatically.
*/
void fftfilt(double *y, const double *b, int n_b, const double *x, int n_x, int n) {
    int i, j, m, nfft, L;
    double *g, *G, *my_b, *B;
    rfftw_plan fftp, ifftp;
    int nextpow2(int A);
    void hc_vec_mul(double *vec_a, const double *vec_b, int n);

    /***** determining the FFT length "nfft" and block length "L" *****/

    if (n == 0) { // default.
        if (n_x > n_b) {
            /* fftfilt chooses the block length L that minimize the number of
           blocks times the number of flops per FFT. */
            int l, min_l;
            double flops, min_flops;
            min_flops = DBL_MAX;
            for (l = 1; l <= n_x; ++l) {
                int p, p2;
                p = nextpow2(n_b + l - 1); // p is a fft length.

                // p2 means 2^p.
                p2 = 1;
                for (j = 0; j < p; ++j)
                    p2 *= 2;

                // FFT flops = 2^p*log2(2^p) = p*2^p = p*p2
                flops = ceil((double) n_x / l) * p * p2;

                /* find the optimum block length, L.
                   FFT flops = 2^p*log2(2^p) = p*2^p = p*p2 */
                if (flops < min_flops) {
                    min_l = l;
                    min_flops = flops;
                }
            }
            L = min_l;

            nfft = 1;
            for (i = 0; i < nextpow2(n_b + L - 1); ++i)
                nfft *= 2;

        } else {
            /* if n_b is greater than or equal to n_x,
           fftfilt uses a single FFT. */
            nfft = 1;
            for (i = 0; i < nextpow2(n_b + n_x - 1); ++i)
                nfft *= 2;
            L = nfft - n_b + 1;
        }

    } else { // specify by user.
        int tmp_n;
        if (n < n_b)
            tmp_n = n_b;
        else
            tmp_n = n;
        // nfft = 2^nextpow2(tmp_n)
        nfft = 1;
        for (i = 0; i < nextpow2(tmp_n); ++i)
            nfft *= 2;
        L = nfft - n_b + 1;
    }

    fprintf(stderr, "fft length nfft = %d, block length L = %d\n", nfft, L);

    /***** initialize the rfftw *****/
    fftp = rfftw_create_plan(nfft, FFTW_REAL_TO_COMPLEX, FFTW_ESTIMATE);
    ifftp = rfftw_create_plan(nfft, FFTW_COMPLEX_TO_REAL, FFTW_ESTIMATE);

    g = vec_new(nfft);
    G = vec_new(nfft);
    my_b = vec_new(nfft);
    B = vec_new(nfft);

    /***** filtering *****/
    vec_fill(y, n_x + n_b - 1, 0.);
    vec_copy(my_b, b, n_b);
    rfftw_one(fftp, my_b, B);

    fprintf(stderr, "excute filtering...");
    for (m = 0; m < (int) ceil((double) n_x / L) - 1; ++m) {
        vec_copy(g, x + m * L, L);
        vec_fill(g + L, nfft - L, 0.);
        rfftw_one(fftp, g, G);
        hc_vec_mul(G, B, nfft);
        rfftw_one(ifftp, G, g);
        vec_scaladd(y + m * L, g, nfft, 1. / nfft);
    }
    vec_fill(g, nfft, 0.);
    vec_copy(g, x + m * L, n_x - m * L);
    rfftw_one(fftp, g, G);
    hc_vec_mul(G, B, nfft);
    rfftw_one(ifftp, G, g);
    vec_scaladd(y + m * L, g, n_x - m * L + n_b - 1, 1. / nfft);
    fprintf(stderr, "done\n");

    vec_delete(g);
    vec_delete(G);
    vec_delete(my_b);
    vec_delete(B);

    rfftw_destroy_plan(fftp);
    rfftw_destroy_plan(ifftp);
}
