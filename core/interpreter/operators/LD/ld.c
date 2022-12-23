#include "ld.h"

interpreter_context LD_do(interpreter_context context, string_args args)
{
    // hashmap* map = context.variables;
    // char* var_name = args.args[1].value;
    // uint8_t var_name_len = args.args[1].len;
    // uintptr_t var;
    // hashmap_get(map, var_name, var_name_len, &var);
    // context.register_A = (int64_t)var;
    // return context;

    stream_descriptor descriptor = program_get_stream_due_name(context.stream_provider_context, args.args[1]);
    uint8_t* raw_data = calloc(256, sizeof(uint8_t));
    size_t pos = 0;
    do{
        stream_dto stream_res = program_get_from_stream(descriptor, 1);
        if (!stream_res.valid){
            free(raw_data);
            context.error_flags |= INTERPRETER_ERROR_INVALID_STREAM;
            return context;
        }
        raw_data[pos] = stream_res.payload[0];
    }while('0' <= raw_data[pos] && raw_data[pos] <= '9' && ++pos);
    int64_t data;
    if(!sscanf((char*)raw_data, "%" SCNd64, &data)){
        free(raw_data);
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERAND;
        return context;
    }
    free(raw_data);
    context.register_A = data;
    return context;
}