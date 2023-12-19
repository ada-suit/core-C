# Makefile for cross and self compiling

CC = gcc
CROSS_CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2
LDFLAGS = -lgpiod

TARGET = bin
SRC_DIR = src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

all: $(TARGET)

self: CC := $(CC)
self: $(TARGET)

cross: CC := $(CROSS_CC)
cross: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ_FILES)
