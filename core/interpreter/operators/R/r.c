#include "r.h"

interpreter_context R_do(interpreter_context context, string_args args)
{
    if (!context.register_A)
        context.logic_operand = 0;
    return context;
}