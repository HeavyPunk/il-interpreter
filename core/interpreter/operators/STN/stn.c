#include "stn.h"

interpreter_context STN_do(interpreter_context context, string_args args)
{
    int64_t A = context.register_A;
    hashmap* cache = context.variables;
    char* key = args.args[1].value;
    size_t key_s = args.args[1].len + 1;
    hashmap_set(cache, key, key_s, (uintptr_t)&A);
    return context;
}