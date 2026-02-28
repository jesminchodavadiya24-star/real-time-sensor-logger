#ifndef FSM_H
#define FSM_H

typedef enum {
    STATE_IDLE,
    STATE_LOGGING,
    STATE_ERROR
} SystemState;

void fsm_init(void);
void fsm_update(int start_signal, int error_signal);
SystemState fsm_get_state(void);

#endif
