/*
  umasig - a sub-routine library for signal processing.

  Copyright (c) 2000-2002 Takahiro Umayahara.
  Author: Takahiro Umayahara

  Questions and comments to: uma@audio.nagaokaut.ac.jp
  
  2000/02/28 - 2002/01/08
 */

#ifndef __UMASIG_H__
#define __UMASIG_H__

#include <stdio.h>

#define PI (3.141592653589793238462643383279502884197169399)
#define TINY (1.0e-100)

typedef struct {
    double re, im;
} complex;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

void ho();

long stream_len(int block_size, FILE *stream);

complex c_mul(complex a, complex b);

complex c_div(complex a, complex b);

complex c_add(complex a, complex b);

complex c_conj(complex x);

double c_abs(complex x);

double c_phase(complex x);

complex c_poler(double abs, double p);

complex c_set(double re_val, double im_val);

complex c_scal(complex c, double val);

double *vec_new(int size);

double *vec_new_from_vec(const double *vec, int size);

double *vec_new_from_stream(FILE *fp, int *n);

double *vec_new_from_file(const char *path_name, int *n);

void vec_delete(double *vec);

void vec_fill(double *vec, int n, double val);

void vec_add(double *vec_a, const double *vec_b, int n);

void vec_mul(double *vec_a, const double *vec_b, int n);

void vec_scal(double *vec, int n, double val);

void vec_scaladd(double *vec_a, const double *vec_b, int n, double val);

void vec_copy(double *vec_a, const double *vec_b, int n);

void vec_push(double *vec, int n, double val);

double vec_pop(double *vec, int n);

double vec_dot(const double *vec_a, const double *vec_b, int n);

double *vec_resize(double *vec, int from_n, int to_n);

double vec_max(const double *vec, int n);

double vec_min(const double *vec, int n);

complex *c_vec_new(int size);

complex *c_vec_new_from_vec(const double *vec, int size);

complex *c_vec_new_from_stream(FILE *fp, int *n);

complex *c_vec_new_from_file(const char *path_name, int *n);

void c_vec_delete(complex *vec);

void c_vec_fill(complex *vec, int n, complex val);

void c_vec_copy(complex *vec_a, const complex *vec_b, int n);

void c_vec_copy_from_vec(complex *vec_a, const double *vec_b, int n);

void c_vec_add(complex *vec_a, const complex *vec_b, int n);

void c_vec_mul(complex *vec_a, const complex *vec_b, int n);

void c_vec_div(complex *vec_a, const complex *vec_b, int n);

void c_vec_scal(complex *vec, int n, complex val);

void c_vec_scaladd(complex *vec_a, const complex *vec_b, int n, complex val);

void c_vec_push(complex *vec, int n, complex val);

complex c_vec_pop(complex *vec, int n);

void fft(complex data[], int n);

void ifft(complex data[], int n);

void power_spect(double *y, const double *x, int n);

void amp_spect(double *y, const double *x, int n);

void amp_spect_dB(double *y, const double *x, int n);

void phase_spect_pv(double *y, const double *x, int n);

void phase_spect(double *y, const double *x, int n);

void gd_spect(double *y, const double *x, int n);

void unwrapping(double *ph, int n);

void min_impres_from_impres(double *y, const double *x, int n);

void TSGD(double *tsgd, const double *gd, int n, int order);

void hanning(double *y, int n);

void hamming(double *y, int n);

void blackman(double *y, int n);

void bartlett(double *y, int n);

void boxcar(double *y, int n);

void gausswin(double *y, int n, double alp);

void sinusoidal_window(double *x, int n, int hop, double a, double b);

void sine_window(double *x, int n);

void uni_random(double *y, int n);

void gauss_random(double *y, int n);

void lconv(double *y, const double *a, const double *b, int na, int nb);

void fcorr_normalize(double *y, const double *a, const double *b, int na, int nb, int fft_points, int bai);

void auto_correlation(double *r, const double *x, int p, int n);

void fractional_delay_using_linear_phase(double *x, int n, int fft_points, double delay);

void parcor_and_lpc(double *k, double *a, double *r, const double *v, int p);

/* fftfilt() requires fftw. (http://www.fftw.org) */
void fftfilt(double *y, const double *b, int n_b, const double *x, int n_x, int n);

int nextpow2(int A);

/* plot() and c_plot() require gnuplot. (http://www.gnuplot.org) */
void plot(const double *x, int n);

void c_plot(const complex *x, int n, char part);

void plot_to_file(FILE *out, const double *x, int n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif //__UMASIG_H__



