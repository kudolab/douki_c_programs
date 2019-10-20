/*
 *  umasig/conv.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/06/16  
 */

/*
 * convolution.
 */

#include <stdlib.h>
#include <stdio.h>
#include "umasig.h"

/*
 * linear convolution, y=a*b.
 * <input> <o> double *y : array pointer (length=na+nb-1)
 *         <i> const double *a : array pointer (length=na) 
 *         <i> const double *b : array pointer (length=nb)
 *         <i> int na : array length
 *         <i> int nb : array length
 */
void lconv(double *y, const double *a, const double *b, int na, int nb)
{
  int i;
  double *reg;
  
  if (na < nb) {
    reg = vec_new(na);
    for (i = 0; i < na + nb - 1; ++i) {
      vec_push(reg, na, i < nb ? b[i] : 0.0);
      y[i] = vec_dot(reg, a, na);
    }
    vec_delete(reg);
  } else {
    reg = vec_new(nb);
    for (i = 0; i < na + nb - 1; ++i) {
      vec_push(reg, nb, i < na ? a[i] : 0.0);
      y[i] = vec_dot(reg, b, nb);
    }
    vec_delete(reg);
  }
}

void fcorr_normalize(double *y, const double *a, const double *b, int na, int nb,int fft_points,int bai)
{
  
  int j, fft_points_expd;
  double real, imag;
  complex *A,*B,*Y;
  complex *A_expd,*B_expd;
  double AA_expd,BB_expd;
  double *tmp;
  
  tmp=(double *)malloc(nb*sizeof(double));
  for (j=0;j<nb;j++) tmp[nb-j-1]=b[j];
  
  fft_points_expd=fft_points*bai;
  
  A = c_vec_new(fft_points);
  c_vec_copy_from_vec(A, a, na);
  B = c_vec_new(fft_points);
  c_vec_copy_from_vec(B, tmp, nb);
  
  A_expd = c_vec_new(fft_points_expd);
  B_expd = c_vec_new(fft_points_expd);
  Y = c_vec_new(fft_points_expd);

  fft(A, fft_points);
  fft(B, fft_points);
  /*zeropadding in the frequency domain for interpolating time signal*/
  for(j=0;j<(int)(fft_points/2);j++){
    A_expd[j].re = A[j].re;
    A_expd[j].im = A[j].im;
    B_expd[j].re = B[j].re;
    B_expd[j].im = B[j].im;
  }
  for(j=0;j<(int)(fft_points/2);j++){
    A_expd[fft_points_expd-1-j].re = A[fft_points-1-j].re;
    A_expd[fft_points_expd-1-j].im = A[fft_points-1-j].im;
    B_expd[fft_points_expd-1-j].re = B[fft_points-1-j].re;
    B_expd[fft_points_expd-1-j].im = B[fft_points-1-j].im;
  }
  c_vec_copy(Y,A_expd,fft_points_expd);
  c_vec_mul(Y,B_expd,fft_points_expd);/*complex multiple for convolution */
  ifft(Y,fft_points_expd);
  
  /*compute an energy for normalizing*/
  ifft(A_expd,fft_points_expd);
  ifft(B_expd,fft_points_expd);
  AA_expd=BB_expd=0.0;
  for (j = 0; j < fft_points_expd;j++) {
    AA_expd+=A_expd[j].re*A_expd[j].re;
    BB_expd+=B_expd[j].re*B_expd[j].re;
  }
  
  for (j = 0; j < fft_points_expd; j++) y[j] = Y[j].re*fft_points_expd/sqrt(AA_expd*BB_expd);
  
  c_vec_delete(A);
  c_vec_delete(B);
  c_vec_delete(Y);

}
