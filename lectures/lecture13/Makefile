CC = gcc
FFLAGS = -03 -Wall -std=c99
TARGET = main
SRCS = main.c matrix.c solve_system.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $( FFLAGS ) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
