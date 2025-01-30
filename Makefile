CC = gcc

CFLAGS = -std=c99 -Wall -Werror -MMD -MP

MAIN = main

SRCS = line_encoding.c chunk.c memory.c debug.c value.c main.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEPS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN) $(OBJS) $(DEPS)
