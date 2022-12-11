#include "file_reader.h"

FILE* file_open(char *filepath, struct FileParams params)
{
    if (!filepath)
        return NULL;
    char* mode = params.mode ? params.mode : "rb";
    FILE* file = fopen(filepath, mode);
    return file;
}

void file_close(FILE *file)
{
    if (!file)
        return;
    fclose(file);
}

stream_result file_get_next_val(FILE *file)
{
    int value = fgetc(file);
    stream_flags flags = 0; 
    if (value != EOF)
        flags = flags | STREAM_FLAG_VALID;
    return (stream_result){(uint8_t) value, flags};
}
