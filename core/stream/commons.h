#ifndef STREAM_COMMONS_H
#define STREAM_COMMONS_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "../../../hashmap/map.h"

typedef struct StreamDto{
    uint8_t* payload;
    size_t len;
    bool valid;
} stream_dto;

typedef struct StreamProviderContext{
    hashmap* streams;
} stream_provider_context;

typedef stream_dto (*stream_getter) (size_t len);
typedef bool (*stream_sender) (stream_dto payload);

typedef struct StreamDescriptor{
    stream_getter payload_getter;
    stream_sender payload_sender;
} stream_descriptor;

typedef stream_descriptor (*stream_descriptor_getter) (void);

#endif
