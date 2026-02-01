#pragma once

typedef struct Game Game; // Forward declaration

void boot_enter(Game *game);
void boot_update(Game *game);
void boot_render(Game *game);
void boot_exit(Game *game);