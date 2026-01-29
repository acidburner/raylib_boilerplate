#pragma once

typedef struct Game Game; // Forward declaration

void in_game_enter(Game *game);
void in_game_update(Game *game);
void in_game_exit(Game *game);