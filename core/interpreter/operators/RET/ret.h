#ifndef RET_H
#define RET_H

#include "../../../context/context.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"

interpreter_context RET_do(interpreter_context context, string_args args);

#endif
