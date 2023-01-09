#ifndef ST_H
#define ST_H

#include <inttypes.h>
#include <stdio.h>
#include "../../../context/context.h"
#include "../../../var/variables.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"
#include "../../../stream/stream.h"

interpreter_context ST_do(interpreter_context context, string_args args);

#endif