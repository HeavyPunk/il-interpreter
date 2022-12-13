#include "parser.h"

invocation_context parse_until_break(reader_source_descriptor descriptor)
{
    size_t buff_size = 256;
    char delimiters[] = {' ', ','};
    char break_symb[] = {';', '\n', '\r'};
    stream_result stream_tmp;
    string_args args;
    size_t raw_args_count = 0;
    char** raw_args = calloc(buff_size, sizeof(char*));
    uint8_t* raw_args_lens = calloc(buff_size, sizeof(uint8_t));
    uint8_t arg_len = 0;
    
//осталось написать логику перезаписывания аргументов в raw_args

    do {
        stream_tmp = get_from_stream(descriptor);
        if (!(stream_tmp.flags & STREAM_FLAG_VALID))
            break;
        char* current_raw_arg = raw_args[raw_args_count];
        if (current_raw_arg == NULL){
            current_raw_arg = malloc(sizeof(char) * buff_size);
            raw_args[raw_args_count] = current_raw_arg;
        }
           
        if (!contains_in(stream_tmp.payload, (uint8_t*) delimiters, sizeof(delimiters)/sizeof(char)) 
            && !contains_in(stream_tmp.payload, (uint8_t*) break_symb, sizeof(break_symb)/sizeof(char))
        ){
            current_raw_arg[arg_len] = stream_tmp.payload;
            arg_len++;
            continue;
        }

        if (contains_in(stream_tmp.payload, (uint8_t*) delimiters, sizeof(delimiters)/sizeof(char))){
            if (0 == arg_len)
                continue;
            raw_args_lens[raw_args_count] = arg_len;
            arg_len = 0;
            raw_args_count++;
            continue;
        }
        if (contains_in(stream_tmp.payload, (uint8_t*) break_symb, sizeof(break_symb)/sizeof(char))){
            raw_args_lens[raw_args_count] = arg_len;
            raw_args_count++;

            args.args = malloc(sizeof(string_arg) * raw_args_count);
            for (size_t i = 0; i < raw_args_count; i++){
                args.args[i] = (string_arg){raw_args[i], raw_args_lens[i]};
            }
            args.len = raw_args_count;
            return (invocation_context){NULL, args};
        }
    } while (stream_tmp.flags & STREAM_FLAG_VALID);
}