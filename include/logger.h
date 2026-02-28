#ifndef LOGGER_H
#define LOGGER_H

#include "circular_buffer.h"

#define FLAG_START  (1 << 0)
#define FLAG_ERROR  (1 << 1)

void logger_init(void);
void logger_update(uint32_t sensor_value, uint8_t flags);

#endif
