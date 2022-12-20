#ifndef R_H
#define R_H

#include "../../../context/context.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"

interpreter_context R_do(interpreter_context context, string_args args);

#endif