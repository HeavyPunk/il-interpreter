#ifndef STRING_ARG_H
#define STRING_ARG_H

#include <stddef.h>
#include <stdint.h>

typedef struct StringArg{
    char* value;
    size_t len;
} string_arg;

typedef struct StringArgs{
    string_arg* args;
    size_t len;
} string_args;

#endif