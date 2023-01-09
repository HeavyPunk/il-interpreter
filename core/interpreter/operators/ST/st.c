#include "st.h"

interpreter_context ST_do(interpreter_context context, string_args args)
{
    if (args.len < 2){
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERANDS_COUNT;
        return context;
    }

    uint8_t* var_name = args.args[1].value;
    size_t var_name_len = args.args[1].len;
    hashmap* var_cache = context.variables;   
    variable_descriptor* variable;
    if (!hashmap_get(var_cache, var_name, var_name_len, (uintptr_t*)&variable)){
        context.error_flags |= INTERPRETER_ERROR_INVALID_VARIABLE;
        return context;
    }
    if (NULL == variable->setter){
        context.error_flags |= INTERPRETER_ERROR_INVALID_VARIABLE;
        return context;
    }
    variable->setter(context, (uintptr_t) variable, (uintptr_t)&context.register_A);
    return context;
}