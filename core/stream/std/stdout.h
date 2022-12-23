#ifndef STREAM_STDOUT_H
#define STREAM_STDOUT_H

#include <stdio.h>
#include "../commons.h"

stream_descriptor stdout_get_descriptor();
bool stdout_send_payload(stream_dto payload);

#endif
