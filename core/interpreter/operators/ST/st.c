#include "st.h"

interpreter_context ST_do(interpreter_context context, string_args args)
{
    // int64_t A = context.register_A;
    // hashmap* cache = context.variables;
    // char* key = args.args[1].value;
    // size_t key_s = args.args[1].len + 1;
    // hashmap_set(cache, key, key_s, (uintptr_t)&A);
    // return context;

    stream_descriptor descriptor = program_get_stream_due_name(context.stream_provider_context, args.args[1]);
    uint8_t* data = calloc(10, sizeof(uint8_t));
    int len = sprintf((char*)data, "%" SCNd64, context.register_A);
    if (!len){
        free(data);
        context.error_flags |= INTERPRETER_ERROR_INVALID_STREAM;
        return context;
    }

    stream_dto dto = {
        .payload = data,
        .len = len,
        .valid = data
    };
    bool send_res = program_send_to_stream(descriptor, dto);
    return context;
}