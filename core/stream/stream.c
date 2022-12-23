#include "stream.h"

stream_provider_context program_streams_init()
{
    hashmap* streams = hashmap_create();
    hashmap_set(streams, "in", sizeof("in") - 1, (uintptr_t)stdin_get_descriptor);
    hashmap_set(streams, "out", sizeof("out") - 1, (uintptr_t)stdout_get_descriptor);
    return (stream_provider_context){.streams = streams};
}

   
stream_descriptor program_get_stream_due_name(stream_provider_context provider_context, string_arg key){
    hashmap* streams = provider_context.streams;
    stream_descriptor_getter getter;
    if(!hashmap_get(streams, key.value, key.len, (uintptr_t*)&getter)){
        return (stream_descriptor){.payload_getter = NULL, .payload_sender = NULL};
    }
    stream_descriptor descriptor = getter();
    return descriptor;
}

stream_dto program_get_from_stream(stream_descriptor descriptor, size_t len)
{
    if(NULL == descriptor.payload_getter)
        return (stream_dto){.valid = 0};
    
    stream_dto res = descriptor.payload_getter(len);
    return res;
}

bool program_send_to_stream(stream_descriptor descriptor, stream_dto payload)
{
    if (NULL == descriptor.payload_sender)
        return 0;
    bool send_res = descriptor.payload_sender(payload);
    if (NULL != payload.payload)
        free(payload.payload);
    return send_res;
}
