CC = gcc

CFLAGS = -std=c99 -Wall -Werror

MAIN = main

HDRS = ./chunk.h ./memory.h ./debug.h ./value.h

SRCS = $(HDRS:.h=.c) main.c

OBJS = $(SRCS:.c=.o)

$(MAIN): $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS): $(HDRS) Makefile

clean:
	rm -f $(MAIN) *.o ./*.o
