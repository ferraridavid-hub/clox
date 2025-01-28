main: chunk.o memory.o debug.o main.c
	gcc -std=c99 -Wall -o main main.c chunk.o memory.o debug.o
