#include <stdio.h>
#include <stdlib.h>

#include "core/interpreter/reader/reader.h"
#include "core/interpreter/parser/parser.h"
#include "core/interpreter/invoker/invoker.h"
#include "core/stream/stream.h"
#include "core/var/variables.h"

int main(){
    char* script_path = "hello.il";
    string_args args;
    
    string_arg arg_path = {script_path, 43};
    string_arg arg_file_mode = {"rb", 2};
    string_arg args_c[] = {arg_path, arg_file_mode};
    
    args.args = args_c;
    args.len = 2;
    reader_source_descriptor desc = open_stream(DESCRIPTOR_TYPE_FILE, args);
    if (!desc.valid){
        printf("Error was couched when trying to open read stream");
        return -1;
    }
    stream_provider_context stream_provider_context = program_streams_init();
    invoker_context inv_c = invoker_init();


    //variables defines
    hashmap* variables = hashmap_create();
    variable_descriptor in_stream_variable = {
        .descriptor = (uintptr_t)"in",
        .getter = stream_variable_getter,
        .setter = NULL
    };
    variable_descriptor out_stream_variable = {
        .descriptor = (uintptr_t)"out",
        .getter = NULL,
        .setter = stream_variable_setter
    };

    hashmap_set(variables, "in", sizeof("in") - 1, (uintptr_t)&in_stream_variable);
    hashmap_set(variables, "out", sizeof("out") - 1, (uintptr_t)&out_stream_variable);

    interpreter_context int_context = {.variables = variables, .stream_provider_context = stream_provider_context};


    parser_context parser_ctx = parse_until_break(desc);
    
    while (parser_ctx.flags & STREAM_FLAG_VALID)
    { 
        int_context = invoke(int_context, parser_ctx, inv_c);
        if (int_context.error_flags & INTERPRETER_STATE_INTERRUPT_EXECUTION)
            break;
        parser_ctx = parse_until_break(desc);
    }
    close_stream(desc);

    return 0;
}
