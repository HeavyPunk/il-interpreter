#ifndef LD_H
#define LD_H

#include "../../../context/context.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"

interpreter_context LD_do(interpreter_context context, string_args args);

#endif