#include <stdio.h>
#include <stdlib.h>

#include "../../include/FileLib_osx.c"

int main(int argc, char *argv[]) {
    int length;
    double *x;

    if (argc != 3) {
        fprintf(stderr, "An argument is insufficient\n");
        fprintf(stderr, "Usage: dv input(.DXX) output(.DXX)\n");
        exit(EXIT_FAILURE);
    }

    length = lenfile(argv[1]);
    x = (double *)malloc(length * sizeof(double));
    if (x == NULL) {
        fprintf(stderr, "memory allocation failed at calloc()\n");
        exit(EXIT_FAILURE);
    }

    AnyFileRead(argv[1], x, length);
    AnyFileWrite(argv[2], x, length);
    free(x);
}
