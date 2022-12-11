#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>
#include "../../../hashmap/map.h"

typedef struct ILInterpreterContext{
    int64_t register_A;
    hashmap* variables;
    uint8_t logic_operand;
} interpreter_context;

#endif