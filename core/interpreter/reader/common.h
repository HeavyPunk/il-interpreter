#ifndef READER_COMMON_H
#define READER_COMMON_H

#include <stdint.h>

typedef enum StreamFlags{
    STREAM_FLAG_VALID = (1 << 7),
    STREAM_FLAG_INVALID = 0,
} stream_flags;

typedef struct StreamResult{
    uint8_t payload;
    uint8_t flags;
} stream_result;
/*
Пусть структура флагов такая:
0: 1 - payload валиден, 0 - не валиден
*/

#endif