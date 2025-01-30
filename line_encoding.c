#include "line_encoding.h"
#include "memory.h"

void initLineEncoding(LineEncoding* encoding) {
    encoding->capacity = 0;
    encoding->count = 0;
    encoding->lines = NULL;
}

void writeLineEncoding(LineEncoding* encoding, int line, size_t offset) {

    // check if we're still in the same line
    if (encoding->count > 0 &&
            encoding->lines[encoding->count - 1].line == line) {
        return;
    }

    // add a new LineStart
    if (encoding->count == encoding->capacity) {
        size_t oldCapacity = encoding->capacity;
        encoding->capacity = GROW_CAPACITY(oldCapacity);
        encoding->lines = GROW_ARRAY(LineStart, encoding->lines,
                oldCapacity, encoding->capacity);
    }

    encoding->lines[encoding->count].line = line;
    encoding->lines[encoding->count].offset = offset;
    encoding->count++;
}


void freeLineEncoding(LineEncoding* encoding) {
    FREE_ARRAY(int, encoding->lines, encoding->capacity);
    initLineEncoding(encoding);
}
