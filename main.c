#include <stdio.h>
#include <stdlib.h>

#include "core/interpreter/reader/reader.h"
#include "core/interpreter/parser/parser.h"
#include "core/interpreter/invoker/invoker.h"
#include "core/stream/stream.h"

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


    interpreter_context int_context = {.variables = hashmap_create(), .stream_provider_context = stream_provider_context};


    parser_context parser_c1 = parse_until_break(desc);
    // interpreter_context int_ctx = invoke(int_context, parser_c1, inv_c);
    
    while (parser_c1.flags & STREAM_FLAG_VALID)
    { 
        int_context = invoke(int_context, parser_c1, inv_c);
        parser_c1 = parse_until_break(desc);
    }
    
    close_stream(desc);
    return 0;
}
