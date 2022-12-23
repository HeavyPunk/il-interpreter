#ifndef READER_H
#define READER_H

#include <stdbool.h>
#include "common.h"
#include "../../../common/string_arg.h"

typedef enum DescriptorType{
    DESCRIPTOR_TYPE_UNDEFINED,
    DESCRIPTOR_TYPE_FILE,
    DESCRIPTOR_TYPE_SOCKET,
    DESCRIPTOR_TYPE_MEM,
} descriptor_type;

typedef struct ReaderSourceDescriptor {
    uintptr_t holder;
    descriptor_type type;
    bool valid;
} reader_source_descriptor;


reader_source_descriptor open_stream(descriptor_type type, string_args args);
void close_stream(reader_source_descriptor descriptor);
stream_result get_from_stream(reader_source_descriptor descriptor);

#endif