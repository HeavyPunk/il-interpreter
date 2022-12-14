#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "../reader/reader.h"
#include "../../context/context.h"
#include "../../../common/utils.h"

typedef enum InvocationContextFlags{
    INVOCATION_CONTEXT_FLAG_VALID = (1 << 7),
} invocation_context_flags;

typedef struct ParserContext{
    string_args args;
    uint8_t flags;
} parser_context;

parser_context parse_until_break(reader_source_descriptor descriptor);

#endif