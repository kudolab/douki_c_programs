/*
 *  umasig/utils.c
 *
 *  Copyright (C) 2000  Takahiro Umayahara
 *
 *  2000/10/25  
 */

/*
 *
 */

#include <stdio.h>
#include "umasig.h"

// for the ``printf debug''
void ho() {
    fprintf(stderr, "ho!\n");
    fflush(stderr);
}

long stream_len(int block_size, FILE *stream) {
    long len;
    fseek(stream, 0L, SEEK_END);
    len = ftell(stream);
    rewind(stream);
    return len / block_size;
}
