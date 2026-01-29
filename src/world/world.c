#include "world.h"
#include "core/log/log.h"

#include <stdlib.h>

#define LOG_CATEGORY "World"

World* world_create(uint32_t width, uint32_t height) {
    World* world = (World*)malloc(sizeof(World));
    if (world) {
        world->width = width;
        world->height = height;
        LOG_INFO("World created with dimensions %ux%u", width, height);
    }
    return world;
}
void world_destroy(World* world) {
    if (world) {
        // Clean up other members as needed
        LOG_INFO("Destroying world...");
        free(world);
    }
}
void world_exit(World* world) {
    if (world) {
        // Perform any necessary cleanup before exiting the world
        LOG_INFO("Exiting world...");
    }
}
void world_update(World* world, double delta_time) {
    if (world) {
        // Update world state based on delta_time
        LOG_INFO("Updating world with delta time: %f", delta_time);
    }
}