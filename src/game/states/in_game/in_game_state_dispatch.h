
#pragma once

// #include "game/game.h"
#include "game/states/input_dispatch_handler.h"

void HandleGameDispatch(Game *game);
void handle_pause(Game *game);
void handle_debug_toggle(Game *game);

static const ActionDispatch IN_GAME_ACTIONS[] = {
    {INPUT_KEY_PAUSE, handle_pause},
    {INPUT_KEY_DEBUG_TOGGLE, handle_debug_toggle},
};