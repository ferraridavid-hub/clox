#include<stdio.h>

#include "debug.h"

void disassembleChunk(Chunk* chunk, const char* name) {
    printf("== %s ==\n", name);

    for (size_t offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

size_t simpleInstruction(const char* name, size_t offset) {
    printf("%s\n", name);
    return offset + 1;
}


size_t disassembleInstruction(Chunk* chunk, size_t offset) {
    printf("%04zu ", offset);

    uint8_t instruction = chunk->code[offset];
    switch(instruction){
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}
