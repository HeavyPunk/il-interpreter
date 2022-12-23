#ifndef INVOKER_H
#define INVOKER_H

#include "../parser/parser.h"
/*
Include all possible operators
*/
#include "../operators/LD/ld.h"
#include "../operators/LDN/ldn.h"
#include "../operators/ST/st.h"
#include "../operators/ADD/add.h"
#include "../operators/MUL/mul.h"
//----------------------

typedef interpreter_context (*operator_handler)(interpreter_context context, string_args args);

typedef struct InvokerContext{
    hashmap* invoker_operators_cache;
} invoker_context;

invoker_context invoker_init();
interpreter_context invoke(interpreter_context int_ctx, parser_context parser_ctx, invoker_context inv_ctx);

#endif