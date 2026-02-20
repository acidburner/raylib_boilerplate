#pragma once

typedef struct Game Game; // Forward declaration

void shutdown_enter(Game *game);
void shutdown_update(Game *game);
void shutdown_render(Game *game);
void shutdown_exit(Game *game);