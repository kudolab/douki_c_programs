/*
 *  umasig/complex.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/03/15  
 */

/*
 * ʣ�ǿ��黻�롼����
 */

#include "umasig.h"
#include <math.h>

complex c_mul(complex a, complex b) {
    complex y;
    y.re = a.re * b.re - a.im * b.im;
    y.im = a.re * b.im + a.im * b.re;
    return y;
}

complex c_div(complex a, complex b) {
    complex y;
    double r, den;
    if (fabs(b.re) >= fabs(b.im)) {
        r = b.im / b.re;
        den = b.re + r * b.im;
        y.re = (a.re + r * a.im) / den;
        y.im = (a.im - r * a.re) / den;
    } else {
        r = b.re / b.im;
        den = b.im + r * b.re;
        y.re = (a.re * r + a.im) / den;
        y.im = (a.im * r - a.re) / den;
    }
    return y;
}

complex c_add(complex a, complex b) {
    a.re += b.re;
    a.im += b.im;
    return a;
}

complex c_conj(complex x) {
    x.im *= -1;
    return x;
}

double c_abs(complex x) {
    return sqrt(x.re * x.re + x.im * x.im);
}

double c_phase(complex x) {
    return atan2(x.im, x.re);
}

complex c_poler(double abs, double p) {
    complex c;
    c.re = abs * cos(p);
    c.im = abs * sin(p);
    return c;
}

complex c_set(double re_val, double im_val) {
    complex c;
    c.re = re_val;
    c.im = im_val;
    return c;
}

complex c_scal(complex c, double val) {
    c.re *= val;
    c.im *= val;
    return c;
}
