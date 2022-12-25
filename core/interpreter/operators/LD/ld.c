#include "ld.h"

interpreter_context LD_do(interpreter_context context, string_args args)
{
    stream_descriptor descriptor = program_get_stream_due_name(context.stream_provider_context, args.args[1]);
    stream_dto stream_res = program_get_from_stream(descriptor, -1);
    if (!stream_res.valid){
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERAND;
        return context;
    }

    int64_t data;
    if(!sscanf((char*)stream_res.payload, "%" SCNd64, &data)){
        context.error_flags |= INTERPRETER_ERROR_INVALID_OPERAND;
        return context;
    }
    context.register_A = data;
    return context;
}