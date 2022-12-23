#ifndef STREAM_STREAM_H
#define STREAM_STREAM_H

#include "commons.h"
#include "../../common/string_arg.h"
#include "../../../hashmap/map.h"

#include "std/stdin.h"
#include "std/stdout.h"


stream_provider_context program_streams_init();
stream_descriptor program_get_stream_due_name(stream_provider_context provider_context, string_arg key);
stream_dto program_get_from_stream(stream_descriptor descriptor, size_t len);
bool program_send_to_stream(stream_descriptor descriptor, stream_dto payload);

#endif