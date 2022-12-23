#ifndef ADD_H
#define ADD_H

#include <inttypes.h>
#include <stdio.h>

#include "../../../context/context.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"

interpreter_context ADD_do(interpreter_context context, string_args args);

#endif
