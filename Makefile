 

CC = gcc
CFLAGS = -g -Ivendor/raygui/src
LDFLAGS = -lraylib -lm -lraygui

SRC_FILES = $(wildcard *.c) 
OBJ_FILES = $(SRC_FILES:.c=.o) 

TARGET = main

OS ?= linux

ifeq ($(OS),windows)
    LDFLAGS += -lopengl32 -lgdi32 -lwinmm -lole32
	TARGET = main.exe
endif

all: run

%.o: %.c 
	$(CC) $< -c $@ $(CFLAGS)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ_FILES)
