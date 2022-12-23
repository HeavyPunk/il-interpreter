#include "reader.h"
#include "file_reader.h"

reader_source_descriptor open_stream(descriptor_type type, string_args args)
{
    reader_source_descriptor res;
    switch (type) {
        case DESCRIPTOR_TYPE_FILE:
            if (NULL == args.args || args.len < 2)
                return (reader_source_descriptor) {0, DESCRIPTOR_TYPE_UNDEFINED};
            struct FileParams file_params = {args.args[1].value};
            FILE* file = file_open(args.args[0].value, file_params);
            res = (reader_source_descriptor){
                .holder = (uintptr_t) file,
                .type = DESCRIPTOR_TYPE_FILE,
                .valid = file
            };
            return res; 
        default:
            return res;
    }
}

void close_stream(reader_source_descriptor descriptor)
{
    switch (descriptor.type)
    {
        case DESCRIPTOR_TYPE_FILE:
            FILE* file = (FILE*)descriptor.holder;
            file_close(file);
            break;
        default:
            break;
    }
}

stream_result get_from_stream(reader_source_descriptor descriptor)
{
    stream_result res = {0, STREAM_FLAG_INVALID};
    if (DESCRIPTOR_TYPE_FILE == descriptor.type){
        FILE* file = (FILE*) descriptor.holder;
        res = file_get_next_val(file);
    }
    return res;
}