#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "line_encoding.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;


typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    LineEncoding lineEncoding;
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);

// return the index of the value inside chunk.constants pool
size_t addConstant(Chunk* chunk, Value value);

int getLine(Chunk* chunk, int instruction);

#endif
