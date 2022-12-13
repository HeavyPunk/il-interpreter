#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include "../reader/reader.h"
#include "../../context/context.h"
#include "../../../common/utils.h"

/*
Include all possible operators
*/
#include "../operators/LD/ld.h"
//----------------------

typedef interpreter_context (*operator_handler)(interpreter_context context, string_args args);

typedef struct InvocationContext{
    operator_handler op_handler;
    string_args args;
} invocation_context;

invocation_context parse_until_break(reader_source_descriptor descriptor);

#endif