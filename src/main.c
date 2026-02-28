#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

int main(void) {

    logger_init();
    srand(time(NULL));

    uint8_t flags = FLAG_START;

    for (int i = 0; i < 50; i++) {

        uint32_t sensor_value = rand() % 1000;

        if (i == 30)
            flags |= FLAG_ERROR;

        if (i == 40)
            flags &= ~FLAG_ERROR;

        logger_update(sensor_value, flags);
    }

    return 0;
}
