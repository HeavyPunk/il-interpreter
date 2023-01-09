#ifndef INTERPRETER_VARIABLES_H
#define INTERPRETER_VARIABLES_H

#include <stdint.h>
#include <inttypes.h>
#include "../../common/utils.h"
#include "../context/context.h"
#include "../stream/stream.h"

typedef uintptr_t (*variable_getter) (interpreter_context int_ctx, uintptr_t var_descriptor);
typedef void (*variable_setter) (interpreter_context int_ctx, uintptr_t var_descriptor, uintptr_t value);

typedef struct VariableDescriptor{
    uintptr_t descriptor;
    variable_getter getter;
    variable_setter setter;
} variable_descriptor;

uintptr_t common_variable_getter(interpreter_context int_ctx, uintptr_t var_descriptor);
void common_variable_setter(interpreter_context int_ctx,  uintptr_t var_descriptor, uintptr_t value);

uintptr_t stream_variable_getter(interpreter_context int_ctx, uintptr_t var_descriptor);
void stream_variable_setter(interpreter_context int_ctx, uintptr_t var_descriptor, uintptr_t value);

#endif

