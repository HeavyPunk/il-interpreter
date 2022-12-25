#include "stdin.h"

stream_descriptor stdin_get_descriptor()
{
    return (stream_descriptor){
        .payload_getter = stdin_get_payload,
        .payload_sender = NULL
    };
}

stream_dto stdin_get_payload(size_t len)
{
    FILE* in_descriptor = freopen(0, "rb", stdin);
    size_t sz = len == -1 ? 256 : len;
    uint8_t* stream_data = malloc(sizeof(uint8_t) * sz);
    if (!fgets((char*)stream_data, sz, in_descriptor)){
        free(stream_data);
        return (stream_dto){
            .valid = false
        };
    }

    return (stream_dto){
        .len = sz,
        .valid = NULL != stream_data,
        .payload = stream_data
    };
}
