CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -O2

SRCS := main.c circular_buffer.c
OBJS := $(SRCS:.c=.o)

TARGET := embedded_dsa_demo

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

