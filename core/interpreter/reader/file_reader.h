#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include "common.h"

struct FileParams{
    char* mode;
};

FILE* file_open(char* filepath, struct FileParams params);
void file_close(FILE* file);
stream_result file_get_next_val(FILE* file);


#endif