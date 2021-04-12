/*
  Program to cut and bring down a wave pattern and to cut and bring down the file of any form
  making by Kudo Akihiro at 2001/09/11
  editing by Onodera Yuki at 2015/06/18

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "FileLib_osx.h"

int main(int argc, char *argv[]) {

    int length;
    int st_point;
    int width;
    int end_point;
    double *x;

    if (argc != 5) {
        fprintf(stderr, "An argument is insufficient\n");
        fprintf(stderr, "this program cut out signal\n");
        fprintf(stderr, "Usage:  cutout in start end out\n");
        exit(EXIT_FAILURE);
    }
    length = lenfile(argv[1]);
    st_point = atoi(argv[2]);
    end_point = atoi(argv[3]);
    width = end_point - (st_point - 1);
    fprintf(stderr, "signal:%s, length is %d --> %d\n", argv[1], length, width);
    x = (double *) calloc(length, sizeof(double));
    AnyFileRead(argv[1], x, length);
    AnyFileWrite(argv[4], &x[st_point - 1], width);

}
