#pragma once
// helpers for file I/O


#include <stdlib.h>
// reads in file as buffer



//saves file to path
bool save_file(const char *path, const void *data, size_t size);