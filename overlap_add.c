/**********************************************
 Overlap-Add Method
 Author:Tetsu TAKIZAWA
 Date:2020.11.25
***********************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "FileLib_osx.h"

#define SAMPLING_FREQ 48000
#define NUM_SLTF 3600
#define NUM_CHANNEL 2
#define NUM_DIRECTION 2

int overlap_add(char *subject, char *sound_name, int move_width, int move_velocity, int start_angle, char *out_dir);
int linear_convolution(double *y, const double *x1, int x1_len, const double *x2, int x2_len);

int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "An argument is insufficient\n");
        fprintf(stderr,
                "this program generates moving sound with specified move_width and move_velocity starting at "
                "designated angle\n");
        fprintf(stderr, "Usage: overlap_add subject sound_file(.DXX) move_width move_velocity start_angle outdir\n");
        exit(EXIT_FAILURE);
    }
    overlap_add(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
    return EXIT_SUCCESS;
}

int overlap_add(char *subject, char *sound_name, int move_width, int move_velocity, int start_angle, char *out_dir) {
    // 移動時間 [s]
    double move_time = (double)move_width / (double)move_velocity;
    // 移動時間 [sample]
    int move_samples = (int)(move_time * SAMPLING_FREQ);
    // 0.1度動くのに必要なサンプル数
    // [s]*[Hz] / [deg] = [sample/deg]
    int move_samples_per_deg = move_samples / move_width;
    printf("%d\n", move_samples_per_deg);

    int sound_len = lenfile(sound_name);
    if (sound_len == -1) {
        fprintf(stderr, "failed to read sound file at lenfile()\n");
        exit(EXIT_FAILURE);
    }
    double *sound = (double *)malloc(sizeof(double) * sound_len);
    if (sound == NULL) {
        fprintf(stderr, "memory allocation failed at malloc\n");
        exit(EXIT_FAILURE);
    }

    char *SLTF_name = (char *)malloc(sizeof(char) * 100);
    sprintf(SLTF_name, "%s/SLTF/SLTF_%d_%s.DDB", subject, 0, "L");
    int SLTF_len = lenfile(SLTF_name);
    if (SLTF_len == -1) {
        fprintf(stderr, "failed to read sound file at lenfile()\n");
        exit(EXIT_FAILURE);
    }

    // SLTFの読み込み
    //    double(*SLTFs)[NUM_CHANNEL][NUM_SLTF];
    //    SLTFs = malloc(sizeof(double) * NUM_CHANNEL * NUM_SLTF * SLTF_len);
    //    if (SLTFs == NULL) {
    //        fprintf(stderr, "memory allocation failed at malloc\n");
    //        exit(EXIT_FAILURE);
    //    }

    //    char *LR;
    //    for (int i = 0; i < NUM_CHANNEL; i++) {
    //        for (int j = 0; j < NUM_SLTF; j++) {
    //            if (i == 0)
    //                LR = "L";
    //            else
    //                LR = "R";
    //            sprintf(SLTF_name, "%s/SLTF/SLTF_%d_%s.DDB", subject, NUM_SLTF, LR);
    //            AnyFileRead(SLTF_name, SLTFs[i][j], SLTF_len);
    //        }
    //    }
    //
    //    free(SLTFs);
    char *direction[NUM_DIRECTION] = {"c", "cc"};
    char *LR[NUM_CHANNEL] = {"L", "R"};
    int move_out_len = move_samples + SLTF_len - 1;
    double *move_out = (double *)malloc(sizeof(double) * move_out_len);
    double *SLTF = (double *)malloc(sizeof(double) * SLTF_len);
    int *used_angles = (int *)malloc(sizeof(int) * move_width);
    int data_angle;
    int conv_len = move_samples_per_deg + SLTF_len - 1;
    double *y = (double *)malloc(sizeof(double) * conv_len);
    char *out_name = (char *)malloc(sizeof(char) * 100);

    int i, j, angle, n, m;
    for (i = 0; i < NUM_DIRECTION; i++) {
        for (j = 0; j < NUM_CHANNEL; j++) {
            for (angle = 0; angle < move_width; angle++) {
                // make angle list
                data_angle = angle % (move_width * 2);
                if (data_angle > move_width) {
                    data_angle = move_width * 2 - data_angle;
                }
                // if direction is "cc" or not
                if (i == 1) {
                    data_angle = -data_angle;
                }
                if (data_angle < 0) {
                    data_angle += 3600;
                }

                sprintf(SLTF_name, "%s/SLTF/SLTF_%d_%s.DDB", subject, (start_angle + data_angle) % 3600, LR[j]);
                AnyFileRead(SLTF_name, SLTF, SLTF_len);
                used_angles[angle] = (start_angle + data_angle) % 3600;
                linear_convolution(y, &sound[move_samples_per_deg * angle], move_samples_per_deg, SLTF, SLTF_len);
                for (n = 0; n < conv_len; n++) {
                    move_out[move_samples_per_deg * angle + n] += y[n];
                }
            }
            // char *a;
            // sprintf(a, "%s", direction[i]);
            // printf("%s", a);
            sprintf(out_name, "%s/move_judge_w%03d_mt%03d_%s_%d_%s.DDB", out_dir, move_width, move_velocity,
                    direction[i], start_angle, LR[j]);
            AnyFileWrite(out_name, move_out, move_out_len);
            fprintf(stderr, "%s: length=%d\n", out_name, move_out_len);
            fprintf(stderr, "used angle=[");
            for (angle = 0; angle < move_width; angle++) {
                fprintf(stderr, "%d ", used_angles[angle]);
            }
            fprintf(stderr, "]\n");
        }
    }
    return 0;
}

int linear_convolution(double *y, const double *x1, int x1_len, const double *x2, int x2_len) {
    int y_len = x1_len + x2_len - 1;
    for (int i = 0; i < x1_len; i++) {
        for (int j = i; j < x2_len + i; j++) {
            y[j] += x1[i] * x2[j - i];
        }
    }
    return 0;
}
