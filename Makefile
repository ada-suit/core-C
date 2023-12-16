# Makefile for cross-compiling for ARM Cortex-A53 using aarch64-linux-gnu-gcc

CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2

TARGET = wavelinkPulse
SRC_FILES = src/main.c

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
