#pragma once

typedef struct Game Game; // Forward declaration

void paused_enter(Game *game);
void paused_update(Game *game);
void paused_render(Game *game);
void paused_exit(Game *game);