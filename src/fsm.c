#include "fsm.h"

static SystemState current_state;

void fsm_init(void) {
    current_state = STATE_IDLE;
}

void fsm_update(int start_signal, int error_signal) {

    switch (current_state) {

        case STATE_IDLE:
            if (start_signal)
                current_state = STATE_LOGGING;
            break;

        case STATE_LOGGING:
            if (error_signal)
                current_state = STATE_ERROR;
            break;

        case STATE_ERROR:
            if (!error_signal)
                current_state = STATE_IDLE;
            break;
    }
}

SystemState fsm_get_state(void) {
    return current_state;
}
