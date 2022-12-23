#ifndef STREAM_STDIN_H
#define STREAM_STDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "../commons.h"

stream_descriptor stdin_get_descriptor();
stream_dto stdin_get_payload(size_t len);

#endif
