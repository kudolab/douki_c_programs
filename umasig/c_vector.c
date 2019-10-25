/*
 *  umasig/c_vector.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/06/15  
 */

/*
 * complex array
 */

#include <stdlib.h>
#include <stdio.h>
#include "umasig.h"

/*
 * allocate a complex array, and pad zeros.
 * <input> <i> int size: length of array
 * <output> complex*: address of array head
 */
complex *c_vec_new(int size) {
    complex *buf;

    buf = (complex *) malloc(sizeof(complex) * size);
    if (buf == NULL) {
        fprintf(stderr, "umasig: memory allocation failed!\n");
        fflush(stderr);
        exit(1);
    }
    c_vec_fill(buf, size, c_set(0, 0));

    return buf;
}

complex *c_vec_new_from_vec(const double *vec, int size) {
    complex *buf;

    buf = c_vec_new(size);
    c_vec_copy_from_vec(buf, vec, size);

    return buf;
}

complex *c_vec_new_from_stream(FILE *fp, int *n) {
    int size;
    complex *buf;

    size = stream_len(sizeof(complex), fp);
    buf = c_vec_new(size);
    fread(buf, sizeof(complex), size, fp);

    *n = size;
    return buf;
}

complex *c_vec_new_from_file(const char *path_name, int *n) {
    FILE *fp;

    if ((fp = fopen(path_name, "rb")) == NULL) {
        fprintf(stderr, "umasig: cannot open file: %s\n", path_name);
        exit(1);
    }

    return c_vec_new_from_stream(fp, n);
}

/*
 * free a complex array.
 * <input> <io> complex *vec: address of array head
 */
void c_vec_delete(complex *vec) {
    if (vec)
        free(vec);
}

/*
 * set array elements.
 * <input> <o> complex *vec: address of array head.
 *         <i> int n: length of array.
 *         <i> double re_val: value to be set (real part).
 *         <i> double im_val: value to be set (imag. part).
 */
void c_vec_fill(complex *vec, int n, complex val) {
    int i;
    for (i = 0; i < n; ++i) {
        vec[i].re = val.re;
        vec[i].im = val.im;
    }
}

void c_vec_copy(complex *vec_a, const complex *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] = vec_b[i];
}

void c_vec_copy_from_vec(complex *vec_a, const double *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        vec_a[i].re = vec_b[i];
        vec_a[i].im = 0;
    }
}

void c_vec_add(complex *vec_a, const complex *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i) {
        vec_a[i].re += vec_b[i].re;
        vec_a[i].im += vec_b[i].im;
    }
}

void c_vec_mul(complex *vec_a, const complex *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] = c_mul(vec_a[i], vec_b[i]);
}

void c_vec_div(complex *vec_a, const complex *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] = c_div(vec_a[i], vec_b[i]);
}


void c_vec_scal(complex *vec, int n, complex val) {
    int i;
    for (i = 0; i < n; ++i)
        vec[i] = c_mul(vec[i], val);
}

void c_vec_scaladd(complex *vec_a, const complex *vec_b, int n, complex val) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] = c_add(vec_a[i], c_mul(val, vec_b[i]));
}

void c_vec_push(complex *vec, int n, complex val) {
    int i;
    for (i = n - 1; i > 0; --i)
        vec[i] = vec[i - 1];
    vec[0] = val;
}

complex c_vec_pop(complex *vec, int n) {
    int i;
    complex val = vec[0];
    for (i = 1; i < n; ++i)
        vec[i - 1] = vec[i];
    vec[n - 1].re = 0;
    vec[n - 1].im = 0;
    return val;
}
