#include "xor.h"

interpreter_context XOR_do(interpreter_context context, string_args args)
{
    hashmap* cache = context.variables;
    int64_t *val;
    hashmap_get(cache, args.args[1].value, args.args[1].len, (uintptr_t*)&val);
    context.register_A = context.register_A ;
    return context;
}