#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.h"

int main(int argc, char *argv[]) {
    int i;
    int length1, length2;
    double *x1, *x2, energy_x1, energy_x2;

    if (argc != 3) {
        fprintf(stderr, "������­��ޤ���\n");
        fprintf(stderr, "output the ILD of hrirs from both ears\n");
        fprintf(stderr, "Usage:calc_ILD in_L(.DXX) in_R(.DXX)\n");
        fprintf(stderr, "output:10.0 * log_10 [(in_R)^2 / (in_L)^2 ]\n");
        exit(EXIT_FAILURE);
    }

    length1 = lenfile(argv[1]);
    length2 = lenfile(argv[2]);

    fprintf(stderr, "in_L:%s  length:%d, ", argv[1], length1);
    fprintf(stderr, "in_R:%s  length:%d\n", argv[2], length2);

    x1 = (double *)calloc(length1, (size_t)sizeof(double));
    x2 = (double *)calloc(length2, (size_t)sizeof(double));
    AnyFileRead(argv[1], x1, length1);
    AnyFileRead(argv[2], x2, length2);

    energy_x1 = energy_x2 = 0.0;
    for (i = 0; i < length1; i++) energy_x1 += x1[i] * x1[i];
    for (i = 0; i < length2; i++) energy_x2 += x2[i] * x2[i];
    fprintf(stdout, "%lf\n", 10.0 * log10(energy_x2 / energy_x1));
}
