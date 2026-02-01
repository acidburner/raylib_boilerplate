#pragma once

#include "game/game.h"
#include "input/input.h"

typedef void (*ActionHandler)(Game *game);

typedef struct ActionDispatch
{
  const InputKey action;
  ActionHandler handler;
} ActionDispatch;
