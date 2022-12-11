#ifndef READER_COMMON_H
#define READER_COMMON_H

#include <stdint.h>

typedef uint8_t stream_flags;

typedef struct StreamResult{
    uint8_t payload;
    stream_flags flags;
} stream_result;
/*
Пусть структура флагов такая:
0: 1 - payload валиден, 0 - не валиден
*/

#endif