#include "s.h"

interpreter_context S_do(interpreter_context context, string_args args)
{
    if(context.register_A)
        context.logic_operand = 1;
    return context;
}