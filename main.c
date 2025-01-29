#include<stdio.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char *argv[argc + 1]) {
    Chunk chunk;
    initChunk(&chunk);

    size_t constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);

    constant = addConstant(&chunk, 0.324);
    writeChunk(&chunk, OP_CONSTANT);
    writeChunk(&chunk, constant);
    
    writeChunk(&chunk, OP_RETURN);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return EXIT_SUCCESS;
}
