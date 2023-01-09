#include "variables.h"

uintptr_t common_variable_getter(interpreter_context int_ctx, uintptr_t var_descriptor)
{
    return ((variable_descriptor*) var_descriptor)->descriptor;
}

void common_variable_setter(interpreter_context int_ctx, uintptr_t var_descriptor, uintptr_t value)
{
    ((variable_descriptor*) var_descriptor)->descriptor = value;
}

uintptr_t stream_variable_getter(interpreter_context int_ctx, uintptr_t var_descriptor)
{
    uint8_t* stream_name = (uint8_t*)((variable_descriptor*) var_descriptor)->descriptor;
    string_arg stream = {
        .value = (char*) stream_name,
        .len = string_len(stream_name)
    };
    stream_descriptor stream_descriptor = program_get_stream_due_name(int_ctx.stream_provider_context, stream);
    stream_dto stream_res = program_get_from_stream(stream_descriptor, -1);

    int64_t data;
    sscanf((char*)stream_res.payload, "%" SCNd64, &data);
    int64_t* stream_var_payload = malloc(sizeof(int64_t));
    *stream_var_payload = data;
    return (uintptr_t)stream_var_payload;
}

void stream_variable_setter(interpreter_context int_ctx, uintptr_t var_descriptor, uintptr_t value)
{
    uint8_t* stream_name = (uint8_t*) ((variable_descriptor*) var_descriptor)->descriptor;
    string_arg stream = {
        .value = (char*) stream_name,
        .len = string_len(stream_name)
    };

    stream_descriptor descriptor = program_get_stream_due_name(int_ctx.stream_provider_context, stream);
    uint8_t* data = calloc(10, sizeof(uint8_t));
    int len = sprintf((char*)data, "%" SCNd64, int_ctx.register_A);

    stream_dto dto = {
        .payload = data,
        .len = len,
        .valid = data
    };
    program_send_to_stream(descriptor, dto);
}
