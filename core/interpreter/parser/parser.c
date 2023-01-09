#include "parser.h"

parser_context parse_until_break(reader_source_descriptor descriptor)
{
    size_t buff_size = 256;
    char delimiters[] = {' ', ','};
    char break_symb[] = {'\n', '\r'};
    char comment_symb = ';';
    stream_result stream_tmp;
    string_args args;
    size_t raw_args_count = 0;
    char** raw_args = calloc(buff_size, sizeof(char*));
    uint8_t* raw_args_lens = calloc(buff_size, sizeof(uint8_t));
    uint8_t arg_len = 0;
    bool is_comment_flag = 0;
    

    do{
        stream_tmp = get_from_stream(descriptor);
        char current_symb = stream_tmp.payload;
        bool is_contains_in_delimiters = contains_in(current_symb, (uint8_t*)delimiters, sizeof(delimiters)/sizeof(char));
        bool is_contains_in_breaks = contains_in(current_symb, (uint8_t*)break_symb, sizeof(break_symb)/sizeof(char));

        char* current_raw_arg = raw_args[raw_args_count];
        if (current_raw_arg == NULL){
            current_raw_arg = malloc(sizeof(char) * buff_size);
            raw_args[raw_args_count] = current_raw_arg;
        }

        if (is_contains_in_breaks){
            if (!raw_args_count && !arg_len){
                is_comment_flag = 0;
                continue;
            }
            if (arg_len){
                current_raw_arg = NULL;
                raw_args_lens[raw_args_count] = arg_len;
                raw_args_count++;
            }
            args.args = malloc(sizeof(string_arg) * raw_args_count);
            for (size_t i = 0; i < raw_args_count; i++){
                char* arg = raw_args[i];
                uint8_t len = raw_args_lens[i];
                arg[len] = 0;
                char* prev_arg = arg;
                arg = normalize_string(prev_arg, len + 1);
                free(prev_arg);
                args.args[i] = (string_arg){arg, len};
            }
            args.len = raw_args_count;
            free(raw_args);
            free(raw_args_lens);
            return (parser_context){
                .args = args,
                .flags = INVOCATION_CONTEXT_FLAG_VALID
            };
        }

        if (!is_contains_in_delimiters && !is_contains_in_breaks){
            if (current_symb == comment_symb || is_comment_flag){
                is_comment_flag = 1;
                continue;
            }
            current_raw_arg[arg_len] = current_symb;
            arg_len++;
            continue;
        }

        if (is_contains_in_delimiters){
            if (!arg_len)
                continue;
            current_raw_arg = NULL;
            raw_args_lens[raw_args_count] = arg_len;
            raw_args_count++;
            arg_len = 0;
        }

    } while (stream_tmp.flags & STREAM_FLAG_VALID);
    
    free(raw_args);
    free(raw_args_lens);
    return (parser_context){
        .flags = 0
    };
} 