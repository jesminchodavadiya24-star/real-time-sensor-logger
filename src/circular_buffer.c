#include "circular_buffer.h"

void cb_init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int cb_is_empty(const CircularBuffer *cb) {
    return cb->count == 0;
}

int cb_is_full(const CircularBuffer *cb) {
    return cb->count == BUFFER_SIZE;
}

int cb_push(CircularBuffer *cb, uint32_t value) {
    if (cb_is_full(cb))
        return -1;

    cb->data[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    return 0;
}

int cb_pop(CircularBuffer *cb, uint32_t *value) {
    if (cb_is_empty(cb))
        return -1;

    *value = cb->data[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    return 0;
}
