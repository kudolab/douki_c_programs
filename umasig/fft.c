/*
 *  umasig/fft.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/02/28  
 */

/*
 * fft and inverse fft.
 */

#include <math.h>
#include <stdlib.h>
#include "umasig.h"

#define SWAP(a, b) tempr=(a);(a)=(b);(b)=tempr

void four1(complex data[], unsigned long nn, int isign) {
    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    n = nn << 1;
    j = 1;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            SWAP(data[j / 2].re, data[i / 2].re);
            SWAP(data[j / 2].im, data[i / 2].im);
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    mmax = 2;
    while (n > mmax) {
        istep = mmax << 1;
        theta = isign * (6.28318530717959 / mmax);
        wtemp = sin(0.5 * theta);
        wpr = -2.0 * wtemp * wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m = 1; m < mmax; m += 2) {
            for (i = m; i <= n; i += istep) {
                j = i + mmax;
                tempr = wr * data[j / 2].re - wi * data[j / 2].im;
                tempi = wr * data[j / 2].im + wi * data[j / 2].re;
                data[j / 2].re = data[i / 2].re - tempr;
                data[j / 2].im = data[i / 2].im - tempi;
                data[i / 2].re += tempr;
                data[i / 2].im += tempi;
            }
            wr = (wtemp = wr) * wpr - wi * wpi + wr;
            wi = wi * wpr + wtemp * wpi + wi;
        }
        mmax = istep;
    }
}

#undef SWAP

void fft(complex data[], int n) {
    void four1(complex data[], unsigned long nn, int isign);
    four1(data, n, 1);
}

void ifft(complex data[], int n) {
    void four1(complex data[], unsigned long nn, int isign);
    four1(data, n, -1);
}

void power_spect(double *y, const double *x, int n) {
    complex *c;
    int i;
    c = c_vec_new_from_vec(x, n);
    fft(c, n);
    //for (i = 0; i <= n/2; ++i)
    for (i = 0; i < n; i++)
        y[i] = c[i].re * c[i].re + c[i].im * c[i].im;
    c_vec_delete(c);
}

void amp_spect(double *y, const double *x, int n) {
    int i;
    power_spect(y, x, n);
    //for (i = 0; i <= n/2; ++i)
    for (i = 0; i < n; i++)
        y[i] = sqrt(y[i]);
}

void amp_spect_dB(double *y, const double *x, int n) {
    int i;
    double max_val;
    power_spect(y, x, n);
    //for (i = 0; i <= n/2; ++i)
    for (i = 0; i <= n / 2; i++)
        y[i] = 10 * log10(sqrt(y[i]) + TINY);
}

void phase_spect_pv(double *y, const double *x, int n) {
    int i;
    complex *c;
    c = c_vec_new_from_vec(x, n);
    fft(c, n);
    y[0] = 0;
    for (i = 1; i <= n / 2; ++i)
        y[i] = -atan2(c[i].im, c[i].re);
    c_vec_delete(c);
}

void phase_spect(double *y, const double *x, int n) {
    phase_spect_pv(y, x, n);
    unwrapping(y, n);
}

/*
  [Reference] ���Φ����¼������ϸ���"�����ΰ�ʿ�경���ٱ��
  �Ѥ���û���ְ���θ�ΨŪɽ����ˡ"�������� D-II��J84-D-II (4), 
  pp.621-628, 2001.
*/
void gd_spect(double *y, const double *x, int n) {
    int i;
    complex *X0, *X1;
    X0 = c_vec_new_from_vec(x, n);
    X1 = c_vec_new(n);
    for (i = 0; i < n; ++i)
        X1[i].im = -i * x[i];
    fft(X0, n);
    fft(X1, n);
    for (i = 0; i < n; ++i) {
        double a = X0[i].re, b = X0[i].im, c = X1[i].re, d = X1[i].im;
        if (a * a + b * b < TINY)
            y[i] = 0;
        else
            y[i] = (-d * a + b * c) / (a * a + b * b);
    }
    c_vec_delete(X0);
    c_vec_delete(X1);
}

void TSGD(double *tsgd, const double *gd, int n, int order) {
    int i;
    complex *GD;
    GD = c_vec_new_from_vec(gd, n);
    ifft(GD, n);
    /*
      for (i = 0; i < order; ++i)
      tsgd[i] = GD[i].re;
      c_vec_delete(GD);
    */

    for (i = order; i < (int) (n / 2); i++) GD[i].re = 0.0;
    for (i = 1; i < (int) (n / 2); i++) GD[n - i].re = GD[i].re;
    fft(GD, n);
    for (i = 0; i < n; i++) tsgd[i] = GD[i].re / n;
    c_vec_delete(GD);

}

void unwrapping(double *ph, int n) {
    int i;
    double base, d0, d1, d2;
    base = 0;
    for (i = 1; i <= n / 2; ++i) {
        ph[i] += base;
        d0 = fabs(ph[i] - ph[i - 1]);
        d1 = fabs(ph[i] + 2.0 * PI - ph[i - 1]);
        d2 = fabs(ph[i] - 2.0 * PI - ph[i - 1]);
        if (d1 > d2) {
            if (d0 > d2) {
                base -= 2.0 * PI;
                ph[i] -= 2.0 * PI;
            }
        } else {
            if (d0 > d1) {
                base += 2.0 * PI;
                ph[i] += 2.0 * PI;
            }
        }
    }
}

/*
  [Reference] Alan. V. Oppenheim, Ronald. W. Schafer,
  "Digital Signal Processing," Prentice Hall, Englewood Cliffs,
  NJ, 1978.
 */
void min_impres_from_impres(double *y, const double *x, int n) {
    int j, fft_points;
    double real, imag;
    complex *X;

    fft_points = 1;
    while (fft_points < n)
        fft_points *= 2;
    fft_points *= 32; // <=========== to avoid aliasing

    X = c_vec_new(fft_points);
    c_vec_copy_from_vec(X, x, n);

    fft(X, fft_points);

    for (j = 0; j < fft_points; ++j) {
        X[j].re = log(sqrt(X[j].re * X[j].re + X[j].im * X[j].im) + TINY);
        X[j].im = 0.0;
    }

    ifft(X, fft_points);

    X[0].re /= fft_points;
    X[0].im = 0.0;
    for (j = 1; j < fft_points; ++j) {
        X[j].re = (j < fft_points / 2) ? (2.0 * X[j].re / fft_points) : 0.0;
        X[j].im = 0.0;
    }

    fft(X, fft_points);

    for (j = 0; j < fft_points; j++) {
        real = exp(X[j].re + TINY) * cos(X[j].im);
        imag = exp(X[j].re + TINY) * sin(X[j].im);
        X[j].re = real;
        X[j].im = imag;
    }

    ifft(X, fft_points);

    for (j = 0; j < n; ++j)
        y[j] = X[j].re / fft_points;

    c_vec_delete(X);
}


/*fractional delay using linear phase component in the frequency domain.*/
void fractional_delay_using_linear_phase(double *x, int n, int fft_points, double delay) {

    int i;
    complex *in, *out, shift;
    double omega;

    in = c_vec_new(fft_points);
    out = c_vec_new(fft_points);

    for (i = 0; i < n; i++) in[i].re = x[i];
    fft(in, fft_points);
    for (i = 0; i < (int) (fft_points / 2); i++) {
        omega = 2.0 * PI / (double) fft_points * (double) i;
        shift.re = cos(omega * delay);/*make a shift factor*/
        shift.im = -sin(omega * delay);
        out[i] = c_mul(in[i], shift);
        out[fft_points - 1 - i].re = out[i].re; /*even symmetory*/
        out[fft_points - 1 - i].im = -out[i].im;/*odd  symmetory*/
    }

    ifft(out, fft_points);
    for (i = 0; i < n; i++) x[i] = out[i].re / fft_points;

    c_vec_delete(in);
    c_vec_delete(out);

}


/*fractional delay using up-sampling.*/
void fractional_delay_using_upsampling(double *x, int n, int fft_points, int bai, double delay) {
    int i, fft_points_expd;
    complex *in, *out, *tmp;
    int delay_int;

    fft_points_expd = fft_points * bai;
    in = c_vec_new(fft_points);
    out = c_vec_new(fft_points_expd);
    tmp = c_vec_new(fft_points_expd);
    for (i = 0; i < n; i++) in[i].re = x[i];
    fft(in, fft_points);
    for (i = 0; i < fft_points / 2; i++) {
        out[i].re = in[i].re;
        out[i].im = in[i].im;
    }
    for (i = 0; i < fft_points / 2; i++) {
        out[fft_points_expd - 1 - i].re = in[fft_points - 1 - i].re;
        out[fft_points_expd - 1 - i].im = in[fft_points - 1 - i].im;
    }
    ifft(out, fft_points_expd);
    for (i = 0; i < fft_points_expd; i++) out[i].re = out[i].re / fft_points;

    delay_int = -(int) (bai * delay - 0.5);
    fprintf(stderr, "delay_int=%d\n", delay_int);
    for (i = delay_int; i < fft_points_expd - delay_int; i++) tmp[i].re = out[i - delay_int].re;
    for (i = 0; i < fft_points_expd; i++) out[i].re = tmp[i].re;

    fft(out, fft_points_expd);
    for (i = 0; i < fft_points / 2; i++) {
        in[i].re = out[i].re;
        in[i].im = out[i].im;
    }
    for (i = 0; i < fft_points / 2; i++) {
        in[fft_points - 1 - i].re = out[fft_points_expd - 1 - i].re;
        in[fft_points - 1 - i].im = out[fft_points_expd - 1 - i].im;
    }
    ifft(in, fft_points);
    for (i = 0; i < n; i++) x[i] = in[i].re / fft_points_expd;

}
