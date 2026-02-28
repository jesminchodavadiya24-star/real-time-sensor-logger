#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdint.h>

#define BUFFER_SIZE 32

typedef struct {
    uint32_t data[BUFFER_SIZE];
    size_t head;
    size_t tail;
    size_t count;
} CircularBuffer;

void cb_init(CircularBuffer *cb);
int cb_push(CircularBuffer *cb, uint32_t value);
int cb_pop(CircularBuffer *cb, uint32_t *value);
int cb_is_empty(const CircularBuffer *cb);
int cb_is_full(const CircularBuffer *cb);

#endif
