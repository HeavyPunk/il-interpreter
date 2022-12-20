#ifndef XORN_H
#define XORN_H

#include "../../../context/context.h"
#include "../../../../common/string_arg.h"
#include "../../../../../hashmap/map.h"

interpreter_context XORN_do(interpreter_context context, string_args args);

#endif