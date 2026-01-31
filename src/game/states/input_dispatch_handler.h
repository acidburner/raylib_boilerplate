#pragma once

#include "game/game.h"
#include "input/input.h"

typedef void (*action_handler)(Game *game);

typedef struct ActionDispatch
{
  InputKey action;
  action_handler handler;
} ActionDispatch;
