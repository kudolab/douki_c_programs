/**********************************************
 Fadein-Fadeout method with Fourier Series Window
 whose differential is zero at switching
 Author:a.kudo
 Date:2003.12.11
 modiefied:2004.07.05
***********************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.h"
#include "umasig.h"

#define a0 ((1.0 + sqrt(2.0)) / 4.0)
#define a1 (0.25 + 0.25 * sqrt((5.0 - 2.0 * sqrt(2.0)) / 2.0))
#define a2 ((1.0 - sqrt(2.0)) / 4.0)
#define a3 (0.25 - 0.25 * sqrt((5.0 - 2.0 * sqrt(2.0)) / 2.0))

int main(int argc, char **argv) {
    double **filter;
    double *in, *in_h, *out_h, *filter_one;
    int i, j, l, K;
    int leng_in, leng_h, leng_out, leng_fil, leng_out_h, leng_in_h;
    int fil_number, out_arg, switch_times, switch_times_limit;
    double *Out, **out;
    double f, theta;
    int dur_time;
    int overlap_time;
    int unit_cycle;
    int *access_fil_number;
    int lex;
    int fil_number_middle;

    if (argc < 6) {
        fprintf(stderr, "bad commmandline format\n");
        fprintf(
            stderr,
            "usage:in(.DXX) imp_res1(.DXX) imp_res2(.DXX)...output(.DXX) duration_time[sample] overlap_time[sample]\n");
        exit(EXIT_FAILURE);
    }

    fil_number = argc - 5;
    out_arg = argc - 3;
    dur_time = atoi(argv[argc - 2]);      /*no overlap time*/
    overlap_time = atoi(argv[argc - 1]);  /*overlap time*/
    unit_cycle = dur_time + overlap_time; /*Time period for switching*/
    lex = 2 * fil_number - 2;             /*lex number for deciding an impulse response used*/
    fil_number_middle = (int)((double)(fil_number / 2.0) + 0.5) -
                        1; /*array number of the transfer function which are convolved firstly*/

    /********************** configuration of signal length ********************/
    leng_in = lenfile(argv[1]);
    leng_fil = lenfile(argv[2]);
    leng_out = leng_in + leng_fil;
    leng_out_h = overlap_time + dur_time + overlap_time;
    leng_in_h = overlap_time + dur_time + overlap_time + 1 - leng_fil;
    /********************************************************/

    /*Deciding the array number of impulse response accessed*/
    if (fil_number == 1) {
        access_fil_number = malloc(sizeof(int) * 1);
        access_fil_number[0] = 0;
    } else {
        access_fil_number = malloc(sizeof(int) * (lex));
        for (i = 0; i < fil_number; i++) access_fil_number[i] = i;
        for (i = fil_number; i < lex; i++) access_fil_number[i] = lex - i;
    }

    fprintf(stderr, "signal length=%d  filter length=%d  filter number=%d\n", leng_in, leng_fil, fil_number);

    in = (double *)calloc(leng_in, sizeof(double));                    /*input*/
    in_h = (double *)calloc(leng_in_h + leng_fil * 2, sizeof(double)); /*picked up input*/
    out_h = (double *)calloc(leng_out_h + leng_fil * 2,
                             sizeof(double));         /*output signal obtained from convolution with picked up input*/
    Out = (double *)calloc(leng_out, sizeof(double)); /*final output signal*/
    filter_one = (double *)calloc(leng_fil, sizeof(double));
    out =
        (double **)malloc(fil_number * sizeof(double)); /*output obtained from convolution with eash impulse response*/
    filter = (double **)malloc(fil_number * sizeof(double)); /*impulse responses*/
    for (i = 0; i < fil_number; i++) {
        out[i] = (double *)calloc(leng_out, sizeof(double));
        filter[i] = (double *)calloc(leng_fil, sizeof(double));
    }

    /**************** Reading input signal ****************/
    AnyFileRead(argv[1], in, leng_in);

    /************** Reading impulse responses *******************/
    for (K = 0; K < fil_number; K++) AnyFileRead(argv[2 + K], &filter[K][0], leng_fil);

    /*Convolution process*/
    /* Figuring case of two impulse responses
       out[0][time] --AAAAAAAAAA----AAAAAAAAAA----AAAAAAAAAA-------
       out[1][time] ---------BBBBBBBBBB----BBBBBBBBBB----BBBBBBBBB-
    */
    switch_times_limit = (int)(leng_out / unit_cycle); /*Total of switching impulse responses*/
    fprintf(stderr, "Total of swithcing = %d times\n", switch_times_limit);

    switch_times = 0; /*number of switching transfer functions*/
    // K=fil_number_middle;/*Setting the array number of switching transfer functions*/
    K = 0;
    for (j = 0; j < leng_in_h + leng_fil * 2; j++) in_h[j] = 0.0;   /*Initialize*/
    for (j = 0; j < leng_out_h + leng_fil * 2; j++) out_h[j] = 0.0; /*Initialize*/
    leng_h = (dur_time + overlap_time + 1) - leng_fil;              /*picked up original signal length of input*/
    for (j = 0; j < leng_h + leng_fil; j++)
        in_h[j] = in[j]; /*picked up input signal: expand the signal length of len_fil for concidering non stationary
                            section*/
    for (j = 0; j < leng_fil; j++)
        filter_one[j] = filter[access_fil_number[(int)(K % lex)]][j]; /*Storing the filter to other array*/
    lconv(out_h, in_h, filter_one, leng_h + leng_fil, leng_fil);      /*Linear convolution with umasig*/
    for (j = dur_time; j < dur_time + overlap_time;
         j++) { /*Weighting with the Fourier series window at the tail becase of the first processing*/
        theta = PI / (double)overlap_time * (double)(j - dur_time);
        f = a0 + a1 * cos(theta) + a2 * cos(2.0 * theta) + a3 * cos(3.0 * theta);
        out_h[j] = out_h[j] * f;
    }
    l = access_fil_number[(int)(K % lex)];
    for (j = 0; j < dur_time + overlap_time; j++) out[l][j] = out_h[j]; /*copy the output singal*/

    K++;
    /*processing except switch_times=0*/
    for (switch_times = 1; switch_times < switch_times_limit; switch_times++, K++) {
        for (j = 0; j < leng_in_h + leng_fil * 2; j++) in_h[j] = 0.0;     /*Initialization*/
        for (j = 0; j < leng_out_h + leng_fil * 2; j++) out_h[j] = 0.0;   /*Initialization*/
        leng_h = (dur_time + overlap_time + overlap_time + 1) - leng_fil; /* picked up input signal length*/
        for (j = 0; j < leng_h + leng_fil * 2; j++)
            in_h[j] = in[j + (switch_times - 1) * unit_cycle + dur_time -
                         leng_fil]; /*picked up the input signal:expand the signal length of len_fil for concidering non
                                       stationary section*/
        for (j = 0; j < leng_fil; j++)
            filter_one[j] = filter[access_fil_number[(int)(K % lex)]][j]; /*Storing the filter data to other array*/
        lconv(out_h, filter_one, in_h, leng_fil, leng_h + leng_fil * 2);  /*Linear convolution*/

        for (j = 0; j < overlap_time; j++) { /*Weighting with the Fourier series window*/
            theta = PI / (double)overlap_time * (double)(j);
            f = a0 - a1 * cos(theta) + a2 * cos(2.0 * theta) - a3 * cos(3.0 * theta);
            out_h[j + leng_fil] = out_h[j + leng_fil] * f;
        }
        for (j = 0; j < overlap_time; j++) {
            theta = PI / (double)overlap_time * (double)(j);
            f = a0 + a1 * cos(theta) + a2 * cos(2.0 * theta) + a3 * cos(3.0 * theta);
            out_h[j + leng_fil + unit_cycle] = out_h[j + leng_fil + unit_cycle] * f;
        }
        l = access_fil_number[(int)(K % lex)];
        for (j = 0; j < unit_cycle + overlap_time; j++)
            out[l][j + (switch_times - 1) * unit_cycle + dur_time] = out_h[j + leng_fil]; /*copy the output signal*/
    }
    /*overlap-add processing*/
    for (i = 0; i < leng_out; i++)
        for (j = 0; j < fil_number; j++) Out[i] = Out[i] + out[j][i];

    AnyFileWrite(argv[out_arg], Out, leng_out);
}
