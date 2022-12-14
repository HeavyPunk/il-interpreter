#include <stdio.h>
#include <stdlib.h>

#include "core/interpreter/reader/reader.h"
#include "core/interpreter/parser/parser.h"
#include "core/interpreter/invoker/invoker.h"

int main(){
    char* script_path = "C:\\Project\\CPP_Labs\\il-interpreter\\hello.il";
    string_args args;
    
    string_arg arg_path = {script_path, 43};
    string_arg arg_file_mode = {"rb", 2};
    string_arg args_c[] = {arg_path, arg_file_mode};
    
    args.args = args_c;
    args.len = 2;
    reader_source_descriptor desc = open_stream(DESCRIPTOR_TYPE_FILE, args);
    parser_context parser_c1 = parse_until_break(desc);
    // parser_context parser_c2 = parse_until_break(desc);

    invoker_context inv_c = invoker_init();
    interpreter_context first_ctx = {.variables = hashmap_create()};
    interpreter_context int_ctx = invoke(first_ctx, parser_c1, inv_c);
    // stream_result res = get_from_stream(desc);
    return 0;
}
