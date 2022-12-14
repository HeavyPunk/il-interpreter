#include "invoker.h"

invoker_context invoker_init(){
    hashmap* operators = hashmap_create();
    hashmap_set(operators, "LD", sizeof("LD") - 1, (uintptr_t)LD_do);
    return (invoker_context){.invoker_operators_cache = operators};
}

interpreter_context invoke(interpreter_context int_ctx, parser_context parser_ctx, invoker_context inv_ctx){
    hashmap* cache = inv_ctx.invoker_operators_cache;
    char* operator = parser_ctx.args.args[0].value;
    size_t key_s = parser_ctx.args.args[0].len;
    operator_handler handler;
    hashmap_get(cache, operator, key_s, (uintptr_t*)&handler);
    interpreter_context new_context = handler(int_ctx, parser_ctx.args);
    return new_context;
}
