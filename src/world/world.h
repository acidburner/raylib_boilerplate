// world representation and management and simulation

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct World {
    // add world-related members here
    uint32_t width;
    uint32_t height;
    // etc.
} World;

World* world_create(uint32_t width, uint32_t height);
void world_destroy(World* world);
void world_exit(World* world);
void world_update(World* world, double delta_time);

