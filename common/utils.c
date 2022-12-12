#include "utils.h"

bool contains_in(uint8_t item, uint8_t* collection, size_t sz){
    if (!collection)
        return false;
    for (size_t i = 0; i < sz; i++)
        if (collection[i] == item)
            return true;
    return false;
}