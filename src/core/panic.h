#pragma once

#include <stdlib.h>
#include <stdio.h>

// panic macro for unimplemented features and critical errors
#define PANIC(format, ...) \
    do { \
        fprintf(stderr, "PANIC: " format "\n", ##__VA_ARGS__); \
    } while (0);

#define NOT_IMPLEMENTED() PANIC("Not Implemented %s --- (%s:%d)", __FUNCTION__, __FILE__, __LINE__)