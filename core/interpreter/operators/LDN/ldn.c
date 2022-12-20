#include "ldn.h"

interpreter_context LDN_do(interpreter_context context, string_args args)
{
    hashmap* map = context.variables;
    char* var_name = args.args[1].value;
    uint8_t var_name_len = args.args[1].len;
    uintptr_t var;
    hashmap_get(map, var_name, var_name_len, &var);
    context.register_A = ~(int64_t)var;
    return context;
}