/*
 *  umasig/window.c
 *
 *  Copyright (C) 2000-2001  Takahiro Umayahara
 *
 *  2000/08/14  
 */

/*
 * window functions
 */

#include <math.h>
#include <stdlib.h>
#include "umasig.h"

void hanning(double *y, int n) {
    int i;
    for (i = 0; i < n; i++)
        y[i] = 0.5 * (1.0 - cos(2.0 * PI * i / (n - 1)));
}

void hamming(double *y, int n) {
    int i;
    for (i = 0; i < n; i++)
        y[i] = 0.54 - 0.46 * cos(2.0 * PI * i / (n - 1));
}

void blackman(double *y, int n) {
    int i;
    for (i = 0; i < n; i++)
        y[i] = 0.42 - 0.5 * cos(2.0 * PI * i / (n - 1)) + 0.08 * cos(4.0 * PI * i / (n - 1));
}

void bartlett(double *y, int n) {
    int i;
    for (i = 0; i < n; i++)
        y[i] = 1 - abs(i - n / 2) / (double) n * 2;
}

void boxcar(double *y, int n) {
    int i;
    for (i = 0; i < n; i++)
        y[i] = 1;
}

/*
  gausswin() returns an n-point Gaussian window. 
  n is a positive integer. 
  alp is the reciprocal of the standard deviation (alp >= 2.0).
  The width of the window is inversely related to the value of alp; 
  a larger value of alp produces a narrower window.
 */
void gausswin(double *y, int n, double alp) {
    int i;
    for (i = 0; i < n; ++i) {
        double r = alp * (i - n / 2.) / (n / 2.);
        y[i] = exp(-0.5 * r * r);
    }
}

/*
 * [Reference]
 * D. W. Griffin and J. S. Lim, "Signal estimation from the modified 
 * short-time Fourier transform," IEEE Trans. Acoust., Speech, 
 * Signal Processing, vol. ASSP-32, pp. 236-243, Apr. 1984.
 */
void sinusoidal_window(double *x, int n, int hop, double a, double b) {
    int i;
    for (i = 0; i < n; ++i)
        x[i] = 2 * sqrt(hop) / sqrt(n) / sqrt(4 * a * a + 2 * b * b) * (a + b * cos(2 * PI * i / n + PI / n));
}

/* [Reference]
 * Anibal J. S. Ferreira, "An odd-DFT based approach to time-scale 
 * expansion of audio signals," IEEE Trans. on Speech and Audio 
 * Processing, vol.7, no.4, July 1999.
 */
void sine_window(double *x, int n) {
    int i;
    for (i = 0; i < n; ++i)
        x[i] = sin(PI / n * (i + 0.5));
}
