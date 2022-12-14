#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "../reader/reader.h"
#include "../../context/context.h"
#include "../../../common/utils.h"

typedef interpreter_context (*operator_handler)(interpreter_context context, string_args args);

typedef enum InvocationContextFlags{
    INVOCATION_CONTEXT_FLAG_VALID = (1 << 7),
} invocation_context_flags;

typedef struct InvocationContext{
    operator_handler op_handler;
    string_args args;
    uint8_t flags;
} invocation_context;

invocation_context parse_until_break(reader_source_descriptor descriptor);

#endif