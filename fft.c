#include <stdlib.h>
#include <math.h>

/***************** --- fft --- *********************************
void fft(xr,xi,m)
    xr[.]   : input/output. double array : dimension=2^m.
              real part of input data/ output data.
    xi[.]   : input/output. double array : dimension=2^m.
              imaginary  part of input data/ output data.
    m       : input.        integer.
              exponent.  i.e., dimension = 2^m.  (nonnegative)
****************************************************************/

void fft(double *xr, double *xi, int m) {
    int h, ih, i, j, k, l, n;
    double a, b, d, tr, ti, ur, ui, wr, wi;
    double sin(), cos();
    double pi = 3.1415926535897932384626433832795;
    if (m <= 0) return;
    n = 1 << m; /* n=2^m; power */
    if (m >= 3)             /** radix-2 FFT **/
    {
        h = n;
        for (l = m; l > 2; l--) {
            k = h;
            h = k / 2;
            ur = 1.0;
            ui = 0.0;
            d = pi / h;
            wr = cos(d);
            wi = -sin(d);
            for (j = 0; j < h; j++) {
                for (i = j; i < n; i += k) {
                    ih = i + h;
                    tr = xr[ih];
                    ti = xi[ih];
                    a = xr[i] - tr;
                    b = xi[i] - ti;
                    xr[ih] = a * ur - b * ui;
                    xi[ih] = a * ui + b * ur;
                    xr[i] += tr;
                    xi[i] += ti;
                }
                a = ur * wr - ui * wi;
                ui = ur * wi + ui * wr;
                ur = a;
            }
        }
    }
    if (m >= 2)             /** 4-point DFT **/
    {
        for (j = 0; j < n; j += 4) {
            tr = xr[j];
            ti = xi[j];
            xr[j] = tr + xr[j + 2];
            xi[j] = ti + xi[j + 2];
            xr[j + 2] = tr - xr[j + 2];
            xi[j + 2] = ti - xi[j + 2];
            tr = xr[j + 1];
            ti = xi[j + 1];
            xr[j + 1] = tr + xr[j + 3];
            xi[j + 1] = ti + xi[j + 3];
            tr = tr - xr[j + 3];
            ti = ti - xi[j + 3];
            xr[j + 3] = ti;
            xi[j + 3] = -tr;
        }
    }
    for (j = 0; j < n; j += 2)    /** 2-point DFT **/
    {
        tr = xr[j];
        xr[j] = tr + xr[j + 1];
        xr[j + 1] = tr - xr[j + 1];
        ti = xi[j];
        xi[j] = ti + xi[j + 1];
        xi[j + 1] = ti - xi[j + 1];
    }
    h = n / 2;
    j = 0;          /** bit reversal **/
    for (i = 0; i < n - 1; i++) {
        if (i < j) {
            tr = xr[j];
            ti = xi[j];
            xr[j] = xr[i];
            xi[j] = xi[i];
            xr[i] = tr;
            xi[i] = ti;
        }
        k = h;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
    }
}


void dft(double *xr, double *xi, int length) {
    int n, k;
    double *tr, *ti, theta;
    double sin(), cos();
    double pi = 3.1415926535897932384626433832795;

    tr = (double *) calloc(length, sizeof(double));
    ti = (double *) calloc(length, sizeof(double));

    theta = 2.0 * pi / (double) length;
    for (k = 0; k < length; k++) {
        for (n = 0; n < length; n++) {
            tr[k] = tr[k] + xr[n] * cos(theta * k * n) + xi[n] * sin(theta * k * n);
            ti[k] = ti[k] + xi[n] * cos(theta * k * n) - xr[n] * sin(theta * k * n);
        }
    }

    for (k = 0; k < length; k++) {
        xr[k] = tr[k];
        xi[k] = ti[k];
    }
}
