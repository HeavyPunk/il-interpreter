#include "stdout.h"

stream_descriptor stdout_get_descriptor()
{
    return (stream_descriptor){
        .payload_getter = NULL,
        .payload_sender = stdout_send_payload
    };
}

bool stdout_send_payload(stream_dto payload)
{
    if (!payload.valid || payload.len < 1 || NULL == payload.payload)
        return 0;
    uint8_t* data = payload.payload;
    printf("%s", data);
    return 1;
}
