#ifndef CLOX_VM_H
#define CLOX_VM_H


#include "common.h"
#include "chunk.h"

typedef struct {
    Chunk* chunk;
    uint8_t* ip;
} Vm;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

void initVm();
void freeVm();
InterpretResult interpret(Chunk* chunk);

#endif
