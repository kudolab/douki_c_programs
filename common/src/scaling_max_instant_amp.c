/*
  making by Kudo Akihiro at 2006/02/06
  editing by Onodera Yuki at 2015/06/18
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/FileLib_osx.c"

int main(int argc, char *argv[]) {
    FILE *fp_input_files, *fp_signal;
    int i, j;
    int file_num;
    double *x;
    char input_files[128];
    char directory_name[128];

    double set_max_value, max_value;
    double scaling_factor;
    int length;
    char buffer;
    char file_name[128];
    char full_pass[128];

    if (argc != 4) {
        fprintf(stderr, "An argument is insufficient");
        fprintf(stderr, "this program cut out signal\n");
        fprintf(stderr, "Usage: scaling_max_instant_amp input_files max_value directory/\n");
        exit(EXIT_FAILURE);
    }
    strcpy(input_files, argv[1]);
    set_max_value = atof(argv[2]);
    strcpy(directory_name, argv[3]);

    if ((fp_input_files = fopen(input_files, "r")) == NULL) {
        fprintf(stderr, "The file name is not correct or does not exist.\n");
        exit(EXIT_FAILURE);
    }

    /*Count of the input file number*/
    file_num = 0;
    while ((buffer = fgetc(fp_input_files)) != EOF) {
        if (buffer == '\n') file_num++;
    }
    fprintf(stderr, "There are %d files as inputs\n", file_num);

    fseek(fp_input_files, 0, SEEK_SET);
    max_value = 1.0;
    for (i = 0; i < file_num; i++) {
        strcpy(full_pass, directory_name);
        fscanf(fp_input_files, "%s", file_name);
        strcat(full_pass, file_name);

        fprintf(stderr, "%s\n", full_pass);

        length = lenfile(full_pass);
        x = (double *)calloc(length, sizeof(double));
        if (x == NULL) {
            fprintf(stderr, "memory allocation failed at calloc()\n");
            exit(EXIT_FAILURE);
        }
        AnyFileRead(full_pass, x, length);
        /*maximum search*/
        for (j = 0; j < length; j++)
            if (fabs(x[j]) > max_value) max_value = fabs(x[j]);
        free(x);
    }
    fprintf(stderr, "max value is %lf\n", max_value);

    scaling_factor = set_max_value / max_value;
    fprintf(stderr, "scaling factor is %lf\n", scaling_factor);
    fseek(fp_input_files, 0, SEEK_SET);
    for (i = 0; i < file_num; i++) {
        strcpy(full_pass, directory_name);
        fscanf(fp_input_files, "%s", file_name);
        strcat(full_pass, file_name);

        length = lenfile(full_pass);
        x = (double *)calloc(length, sizeof(double));
        if (x == NULL) {
            fprintf(stderr, "memory allocation failed at calloc()\n");
            exit(EXIT_FAILURE);
        }
        AnyFileRead(full_pass, x, length);
        /*Heaviness charge account*/
        for (j = 0; j < length; j++) x[j] *= scaling_factor;
        AnyFileWrite(full_pass, x, length);
        free(x);
    }
}
