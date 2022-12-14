#include <stdio.h>
#include <stdlib.h>

#include "core/interpreter/reader/reader.h"
#include "core/interpreter/parser/parser.h"

int main(){
    char* script_path = "C:\\Project\\CPP_Labs\\il-interpreter\\hello.il";
    string_args args;
    
    string_arg arg_path = {script_path, 43};
    string_arg arg_file_mode = {"rb", 2};
    string_arg args_c[] = {arg_path, arg_file_mode};
    
    args.args = args_c;
    args.len = 2;
    reader_source_descriptor desc = open_stream(DESCRIPTOR_TYPE_FILE, args);
    invocation_context inv_c1 = parse_until_break(desc);
    invocation_context inv_c2 = parse_until_break(desc);

    // stream_result res = get_from_stream(desc);
    return 0;
}
