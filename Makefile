# Makefile for cross and self compiling

CC = gcc
CROSS_CC = aarch64-linux-gnu-gcc
CFLAGS = -Wall -O2
LDFLAGS = -lgpiod -lrt
TARGET = bin
SRC_DIR = src
OBJ_DIR = obj
COMPONENTS_DIR = $(SRC_DIR)/components
SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(COMPONENTS_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP_FILES := $(OBJ_FILES:.o=.d)

CROSS_CFLAGS = -Wall -O2 -march=armv8-a -static 
INCLUDES = -I$(COMPONENTS_DIR)

.PHONY: all self cross clean

all: $(TARGET)

self: CC := $(CC)
self: $(TARGET)

cross: CC := $(CROSS_CC)
cross: CFLAGS += $(CROSS_CFLAGS)
cross: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(COMPONENTS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -f $(TARGET) $(OBJ_FILES) $(DEP_FILES)
