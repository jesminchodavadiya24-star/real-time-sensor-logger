#include <stdio.h>
#include "logger.h"
#include "fsm.h"

static CircularBuffer buffer;

void logger_init(void) {
    cb_init(&buffer);
    fsm_init();
}

void logger_update(uint32_t sensor_value, uint8_t flags) {

    int start = flags & FLAG_START;
    int error = flags & FLAG_ERROR;

    fsm_update(start, error);

    if (fsm_get_state() == STATE_LOGGING) {

        if (cb_push(&buffer, sensor_value) == 0) {
            printf("Logged: %u\n", sensor_value);
        }
    }

    if (fsm_get_state() == STATE_ERROR) {
        printf("System Error Detected\n");
    }
}
