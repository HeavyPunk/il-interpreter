#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool contains_in(uint8_t item, uint8_t* collection, size_t sz);
char* normalize_string(char* str, size_t true_sz);

#endif