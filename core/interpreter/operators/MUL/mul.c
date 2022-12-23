#include "mul.h"

interpreter_context MUL_do(interpreter_context context, string_args args)
{
    if (args.len < 2){
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERANDS_COUNT;
        return context;
    }
    char* number_str = args.args[1].value;
    int64_t number;
    if (!sscanf(number_str, "%" SCNd64, &number)){
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERAND;
        return context;
    }
    context.register_A *= number;
    return context;
}