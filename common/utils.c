#include "utils.h"

bool contains_in(uint8_t item, uint8_t* collection, size_t sz){
    if (!collection)
        return false;
    for (size_t i = 0; i < sz; i++)
        if (collection[i] == item)
            return true;
    return false;
}

char *normalize_string(char *str, size_t true_sz){
    char* res = calloc(true_sz, sizeof(char));
    char* ptr = str;
    for (size_t i = 0; i < true_sz && *ptr; i++)
        res[i] = str[i];
    return res;
}

size_t string_len(uint8_t *str){
    uint8_t i = 0;
    for (; i < 255 && str[i]; i++);
    return i % 255;
}
