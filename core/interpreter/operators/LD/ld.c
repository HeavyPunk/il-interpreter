#include "ld.h"

interpreter_context LD_do(interpreter_context context, string_args args)
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
        int64_t new_var;
        if(!sscanf(var_name, "%" SCNd64, &new_var)){
            context.error_flags |= INTERPRETER_ERROR_INVALID_OPERAND;
            return context;//unsupported operation (f.e. LD abc)   
        }
        context.register_A = new_var;
        return context;
    }
    if (NULL == variable->getter){
        context.error_flags |= INTERPRETER_ERROR_INVALID_VARIABLE;
        return context;
    }
    uintptr_t variable_value = variable->getter(context, (uintptr_t)variable);
    context.register_A = *(int64_t*)variable_value;
    return context;
}