 

CC = gcc
CFLAGS = -g
LDFLAGS = -lraylib -lm -lopengl32 -lgdi32 -lwinmm

SRC_FILES = $(wildcard *.c) 
OBJ_FILES = $(SRC_FILES:.c=.o) 

TARGET = main

all: run

%.o: %.c 
	$(CC) $< -c $@ $(CFLAGS)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJ_FILES)