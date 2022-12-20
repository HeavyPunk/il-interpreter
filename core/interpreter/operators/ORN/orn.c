#include "orn.h"

interpreter_context ORN_do(interpreter_context context, string_args args)
{
    hashmap* cache = context.variables;
    int64_t* val;
    if (!hashmap_get(cache, args.args[1].value, args.args[1].len, (uintptr_t*)&val))
        return context;
    context.register_A = context.register_A | ~*val;
    return context;
}