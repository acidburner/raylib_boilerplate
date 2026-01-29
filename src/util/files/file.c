#include "file.h"

#include <stdio.h>
#include <stdbool.h>

void * read_file(const char *path, size_t *out_size) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    void *buffer = malloc(size);
    if (!buffer) {
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, size, file);
    fclose(file);
    if (out_size) {
        *out_size = size;
    }
    return buffer;
}

bool save_file(const char *path, const void *data, size_t size) {
    FILE *file = fopen(path, "wb");
    if (!file) {
        return false;
    }
    size_t written = fwrite(data, 1, size, file);
    fclose(file);
    return written == size; // return true if all bytes were written
}