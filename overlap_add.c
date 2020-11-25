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

int overlap_add(char *subject, char *sound_name, int move_width, int move_velocity, int end_angle, char *outdir) {
    // 移動時間 [s]
    double move_time = (double)move_width / (double)move_velocity;
    // 移動時間 [sample]
    int move_samples = (int)move_time * SAMPLING_FREQ;
    // 0.1度動くのに必要なサンプル数
    // [s]*[Hz] / [deg] = [sample/deg]
    int dwellingSamples = move_samples / move_width;

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

    char *SLTF_name;
    sprintf(SLTF_name, "%s/SLTF/SLTF_%d_%s.DDB", subject, 0, "L");
    int SLTF_len = lenfile(SLTF_name);
    if (SLTF_len == -1) {
        fprintf(stderr, "failed to read sound file at lenfile()\n");
        exit(EXIT_FAILURE);
    }

    // SLTFの読み込み
    double(*SLTFs)[NUM_CHANNEL][NUM_SLTF];
    SLTFs = malloc(sizeof(double) * NUM_CHANNEL * NUM_SLTF * SLTF_len);
    if (SLTFs == NULL) {
        fprintf(stderr, "memory allocation failed at malloc\n");
        exit(EXIT_FAILURE);
    }

    char *LR;
    for (int i = 0; i < NUM_CHANNEL; i++) {
        for (int j = 0; j < NUM_SLTF; j++) {
            if (i == 0)
                LR = "L";
            else
                LR = "R";
            sprintf(SLTF_name, "%s/SLTF/SLTF_%d_%s.DDB", subject, NUM_SLTF, LR);
            AnyFileRead(SLTF_name, SLTFs[i][j], SLTF_len);
        }
    }

    free(SLTFs);
}
