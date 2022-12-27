#include "ret.h"

interpreter_context RET_do(interpreter_context context, string_args args)
{
    context.state_flags |= INTERPRETER_STATE_INTERRUPT_EXECUTION; 
    return context;
}