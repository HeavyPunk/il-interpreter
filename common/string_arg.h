#ifndef STRING_ARG_H
#define STRING_ARG_H

#include <stdint.h>

typedef struct StringArg{
    char* value;
    uint8_t len;
} string_arg;

typedef struct StringArgs{
    string_arg* args;
    uint8_t len;
} string_args;

#endif