# Makefile for cross and self compiling

CC = gcc
CROSS_CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2
LDFLAGS = -lgpiod

TARGET = wavelinkPulse
SRC_FILES = src/main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(TARGET)

# Compile on ARM for ARM
self: CC := $(CC)
self: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile on x86 for ARM
cross: CC := $(CROSS_CC)
cross: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_FILES)
