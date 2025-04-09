#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"

bool Init_Circular_Buffer(CircularBuffer *cb, size_t size, void (*callback)(void)) {
    if (!cb || size == 0) return false;

    cb->buffer = (char *)malloc(size);
    if (!cb->buffer) return false;

    cb->max = size;
    cb->head = 0;
    cb->tail = 0;
    cb->full = false;
    cb->bufferUpdateCallback = callback;

    return true;
}

void Free_Circular_Buffer(CircularBuffer *cb) {
    if (cb && cb->buffer) {
        free(cb->buffer);
        cb->buffer = NULL;
    }
}

bool Is_Buffer_Full(CircularBuffer *cb) {
    return cb->full;
}

bool Is_Buffer_Empty(CircularBuffer *cb) {
    return (!cb->full && (cb->head == cb->tail));
}

bool Write_To_Buffer(CircularBuffer *cb, char data) {
    if (Is_Buffer_Full(cb)) return false;

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % cb->max;
    cb->full = (cb->head == cb->tail);

    if (cb->bufferUpdateCallback) {
        cb->bufferUpdateCallback();
    }

    return true;
}

bool Read_From_Buffer(CircularBuffer *cb, char *data) {
    if (Is_Buffer_Empty(cb)) return false;

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->max;
    cb->full = false;

    return true;
}

void Print_Buffer(CircularBuffer *cb) {
    printf("Buffer Contents: ");
    size_t idx = cb->tail;
    size_t count = (cb->head + cb->max - cb->tail) % cb->max;

    if (cb->full) count = cb->max;

    for (size_t i = 0; i < count; ++i) {
        printf("%c ", cb->buffer[idx]);
        idx = (idx + 1) % cb->max;
    }
    printf("\n");
}

