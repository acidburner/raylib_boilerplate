
#pragma once

// #include "game/game.h"
#include "game/input_dispatch_handler.h"

void HandleGameDispatch(Game *game);
void handle_pause(Game *game);

static const ActionDispatch IN_GAME_ACTIONS[] = {
    {INPUT_KEY_PAUSE, handle_pause},
};