#include "in_game_state_dispatch.h"
#include "core/log/log.h"
#include <stdlib.h>

void HandleGameDispatch(Game *game)
{
  InputSystem *input = game->input;
  if (!input)
    return;

  for (size_t i = 0; i < ARRAY_SIZE(IN_GAME_ACTIONS); ++i)
  {
    if (input_action_pressed(input, IN_GAME_ACTIONS[i].action))
    {
      IN_GAME_ACTIONS[i].handler(game);
    }
  }
}

