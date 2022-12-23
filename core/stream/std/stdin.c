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
    size_t sz = 0;
    int stream_data = fgetc(in_descriptor);

    uint8_t* data = malloc(sizeof(uint8_t) * len);

    while (sz < len && EOF != stream_data){
        data[sz] = (uint8_t)stream_data;
        sz++;
        stream_data = fgetc(in_descriptor);
    }

    return (stream_dto){
        .len = sz,
        .valid = sz == len,
        .payload = data
    };
}
