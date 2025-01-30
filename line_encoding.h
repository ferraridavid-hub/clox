#ifndef challenge_line_encoding_h
#define challenge_line_encoding_h

#include "common.h"

typedef struct {
    int line;   
    int offset;
} LineStart;


typedef struct {
    size_t capacity;
    size_t count;
    LineStart* lines;
} LineEncoding;


void initLineEncoding(LineEncoding*);
void writeLineEncoding(LineEncoding*, int line, size_t offset);
void freeLineEncoding(LineEncoding*);

#endif
