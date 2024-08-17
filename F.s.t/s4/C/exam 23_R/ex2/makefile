CC = gcc

CFLAGS = -Wall -Wextra -std=c11

SRCS = t.c fun.c
HDRS = fun.h
TARGET = t

all: $(TARGET)
 $(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.phony: all clean
