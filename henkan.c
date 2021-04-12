#include <stdio.h>
#include <stdlib.h>
#include "FileLib_osx.h"

int main(int argc, char *argv[]) {
    (void)argc;
    int len;
    double *data;

    len = lenfile(argv[1]);
    data = (double *) malloc(sizeof(double) * len);

    AnyFileRead(argv[1], data, len);

    AnyFileWrite(argv[2], data, len);
}
