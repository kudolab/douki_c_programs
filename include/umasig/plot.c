/*
  Copyright (c) 2000 Takahiro Umayahara.
  Author: Takahiro Umayahara

  Questions and comments to: <mailto:zxa01055@nifty.ne.jp>
  
  2000/02/28	
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "umasig.h"

#define PANIC(a) do { \
                perror(a); \
                if (temp_name) unlink(temp_name);\
                exit(1);\
        } while(0)

void plot(const double *x, int n) {
    FILE *command, *data;
    char *temp_name = NULL;
    int i;

    if ((temp_name = tmpnam((char *) 0)) == 0) PANIC("tmpnam failed");
    if (mkfifo(temp_name, S_IRUSR | S_IWUSR) != 0) PANIC("mkfifo failed");
    command = popen("gnuplot", "w");
    fprintf(command, "plot \"%s\" with lines\n", temp_name);
    fflush(command);
    data = fopen(temp_name, "w");
    for (i = 0; i < n; i++) {
        fprintf(data, "%g\n", x[i]);
    }
    fclose(data);
    fprintf(stderr, "press enter to continue...");
    fflush(stderr);
    getchar();

    pclose(command);
    unlink(temp_name);
}

void c_plot(const complex *x, int n, char part) {
    FILE *command, *data;
    char *temp_name = NULL;
    int i;

    if ((temp_name = tmpnam((char *) 0)) == 0) PANIC("tmpnam failed");
    if (mkfifo(temp_name, S_IRUSR | S_IWUSR) != 0) PANIC("mkfifo failed");
    command = popen("gnuplot", "w");
    fprintf(command, "plot \"%s\" with lines\n", temp_name);
    fflush(command);
    data = fopen(temp_name, "w");

    if (part == 0) {
        for (i = 0; i < n; i++)
            fprintf(data, "%g\n", x[i].re);
    } else {
        for (i = 0; i < n; i++)
            fprintf(data, "%g\n", x[i].im);
    }

    fclose(data);
    fprintf(stderr, "press enter to continue...");
    fflush(stderr);
    getchar();

    pclose(command);
    unlink(temp_name);
}

void plot_to_file(FILE *out, const double *x, int n) {
    int i;
    for (i = 0; i < n; ++i)
        fprintf(out, "%g\n", x[i]);
}
