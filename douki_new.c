#include <stdio.h>
#include <stdlib.h>
#include "FileLib_osx.h"

int main(int argc, char *argv[]) {

    FILE *fp;
    int i, j, n, DOUKI_START, mcode_len, len, NUM_OF_REPETITION;
    double *douki_data, *rec_data;

    if (argc != 5) {
        fprintf(stderr, "this program calculates average using data obtained from repeatition measurement\n");
        fprintf(stderr, "douki_new input_file_name output_file_name(.DXX) douki_num douki_file(.DDB)\n");
        exit(EXIT_FAILURE);
    }

    mcode_len = lenfile(argv[1]);
    douki_data = (double *) malloc(sizeof(double) * mcode_len);

    len = lenfile(argv[2]);
    rec_data = (double *) malloc(sizeof(double) * len);
    AnyFileRead(argv[2], rec_data, len);

    NUM_OF_REPETITION = atoi(argv[3]);

    /* Synchronous addtion method */
//    fp = fopen("DOUKI_START","r");
//    if (fp==NULL) exit(EXIT_FAILURE);
//    fscanf(fp,"%d\n",&DOUKI_START);
//    fclose(fp);
//    DOUKI_START = DOUKI_START + mcode_len;
    DOUKI_START = 0;
    fprintf(stderr, "DOUKI_START:%d\n", DOUKI_START);

    for (i = 0; i < mcode_len; i++) douki_data[i] = 0.;
    j = 0;
    n = 0;// number of douki
    for (i = DOUKI_START; i < len; i++, j++) {
        if (j == mcode_len) {
            j = 0;
            n++;
        }
        if (n == NUM_OF_REPETITION) break;
        douki_data[j] = douki_data[j] + rec_data[i];
    }

    for (i = 0; i < mcode_len; i++) douki_data[i] = (douki_data[i] / NUM_OF_REPETITION);

    AnyFileWrite(argv[4], douki_data, mcode_len);
    fprintf(stderr, "calculation has finished:%s\n", argv[4]);

    exit(EXIT_SUCCESS);
}
