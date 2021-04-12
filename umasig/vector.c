/*
 *  umasig/vector.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/06/15  
 */

/*
 * double array
 */

#include <stdlib.h>
#include <stdio.h>
#include "umasig.h"

/*
 * allocate a double array, and pad zeros.
 * <input> <i> int size: length of array
 * <output> double*: address of array head
 */
double *vec_new(int size) {
    double *buf;

    buf = (double *) malloc(sizeof(double) * size);
    if (buf == NULL) {
        fprintf(stderr, "umasig: memory allocation failed!\n");
        fflush(stderr);
        exit(1);
    }

    vec_fill(buf, size, 0);

    return buf;
}

double *vec_new_from_vec(const double *vec, int size) {
    double *buf;

    buf = vec_new(size);
    vec_copy(buf, vec, size);

    return buf;
}

double *vec_new_from_stream(FILE *fp, int *n) {
    int size;
    double *buf;

    size = stream_len(sizeof(double), fp);
    buf = vec_new(size);
    fread(buf, sizeof(double), size, fp);

    *n = size;
    return buf;
}

double *vec_new_from_file(const char *path_name, int *n) {
    FILE *fp;

    if ((fp = fopen(path_name, "rb")) == NULL) {
        fprintf(stderr, "umasig: cannot open file: %s\n", path_name);
        exit(1);
    }

    return vec_new_from_stream(fp, n);
}

/*
 * free a double array.
 * <input> <io> double *vec: address of array head.
 */
void vec_delete(double *vec) {
    if (vec)
        free(vec);
}

/*
 * set array elements.
 * <input> <o> double *vec: address of array head.
 *         <i> int n: lenght of array
 *         <i> double val: value to be set
 */
void vec_fill(double *vec, int n, double val) {
    int i;
    for (i = 0; i < n; ++i)
        vec[i] = val;
}

/*
 * add two array elements. a = a + b.
 * <input> <io> double *vec_a: address of array head
 *         <i> const double *vec_b: address of array head
 *         <i> int n: length of array.
 */
void vec_add(double *vec_a, const double *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] += vec_b[i];
}

void vec_mul(double *vec_a, const double *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] *= vec_b[i];
}

/*
 * scal array elements.
 * <input> <io> double *vec: address of array head
 *         <i> int n: length of array
 *         <i> double val: scal gain
 */
void vec_scal(double *vec, int n, double val) {
    int i;
    for (i = 0; i < n; ++i)
        vec[i] *= val;
}

void vec_scaladd(double *vec_a, const double *vec_b, int n, double val) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] += val * vec_b[i];
}

void vec_copy(double *vec_a, const double *vec_b, int n) {
    int i;
    for (i = 0; i < n; ++i)
        vec_a[i] = vec_b[i];
}

void vec_push(double *vec, int n, double val) {
    int i;
    for (i = n - 1; i > 0; --i)
        vec[i] = vec[i - 1];
    vec[0] = val;
}

double vec_pop(double *vec, int n) {
    int i;
    double val = vec[0];
    for (i = 1; i < n; ++i)
        vec[i - 1] = vec[i];
    vec[n - 1] = 0;
    return val;
}

double vec_dot(const double *vec_a, const double *vec_b, int n) {
    int i;
    double y = 0;
    for (i = 0; i < n; ++i)
        y += vec_a[i] * vec_b[i];
    return y;
}

double vec_max(const double *vec, int n) {
    int i;
    double max_val = vec[0];
    for (i = 1; i < n; ++i) {
        if (max_val < vec[i])
            max_val = vec[i];
    }
    return max_val;
}

double vec_min(const double *vec, int n) {
    int i;
    double min_val = vec[0];
    for (i = 1; i < n; ++i) {
        if (min_val > vec[i])
            min_val = vec[i];
    }
    return min_val;
}
