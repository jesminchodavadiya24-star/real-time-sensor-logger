CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
INCLUDES = -Iinclude

SRC = src/main.c src/logger.c src/fsm.c src/circular_buffer.c
TARGET = sensor_logger

all:
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
