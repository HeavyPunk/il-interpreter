#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>
#include "../stream/commons.h"
#include "../../../hashmap/map.h"

typedef enum ErrorFlagsEnum{
    INTERPRETER_ERROR_OPERATOR_NOT_FOUND = (1 << 7),
    INTERPRETER_ERROR_INVALID_OPERANDS_COUNT = (1 << 6),
    INTERPRETER_ERROR_INVALID_OPERAND = (1 << 5), 
    INTERPRETER_ERROR_INVALID_VARIABLE = (1 << 4)
} error_flags;

typedef enum InterpreterStateFlags{
    INTERPRETER_STATE_INTERRUPT_EXECUTION = (1 << 7)
} interpreter_state_flags;

typedef struct ILInterpreterContext{
    int64_t register_A;
    hashmap* variables;
    uint8_t logic_operand;
    
    stream_provider_context stream_provider_context;

    uint8_t error_flags;
    uint8_t state_flags;
} interpreter_context;


#endif