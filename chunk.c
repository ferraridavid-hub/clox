#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->code = NULL;
    initLineEncoding(&chunk->lineEncoding);
    initValueArray(&chunk->constants);
}


void writeChunk(Chunk* chunk, uint8_t byte, int line) {
    if (chunk->count == chunk->capacity) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code,
                oldCapacity, chunk->capacity);
    } 

    writeLineEncoding(&chunk->lineEncoding, line, chunk->count);
    chunk->code[chunk->count] = byte;
    chunk->count++;
}


void freeChunk(Chunk* chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeLineEncoding(&chunk->lineEncoding);
    initChunk(chunk);
    freeValueArray(&chunk->constants);
}


size_t addConstant(Chunk* chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}


int getLine(Chunk* chunk, int instruction) {
    for (size_t i = 0; i < chunk->lineEncoding.count; i++) {
        if (instruction < chunk->lineEncoding.lines[i].offset) {
            return chunk->lineEncoding.lines[i - 1].line;
        }
    }
    return -1;
}
