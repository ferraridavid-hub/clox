#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

typedef struct {
    size_t capacity;
    size_t count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* valueArray);
void writeValueArray(ValueArray* valueArray, Value value);
void freeValueArray(ValueArray* valueArray);

#endif 
