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

void handle_pause(Game *game) {
  if (input_action_pressed(game->input, INPUT_KEY_PAUSE))
  {
    update_game_state(game, GAME_STATE_PAUSED);
  }
}

void handle_debug_toggle(Game *game) {
  if (input_action_pressed(game->input, INPUT_KEY_DEBUG_TOGGLE))
  {
    game->debug_overlay_enabled = !game->debug_overlay_enabled;
    LOG_INFO("Debug overlay toggled: %s", game->debug_overlay_enabled ? "ON" : "OFF");
  }
}