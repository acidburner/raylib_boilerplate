
#include "global_state_input.h"
#include "global_input_handlers/debug.h"
#include "game/game.h"
#include "core/log/log.h"

void HandleGlobalInput(Game *game)
{
  InputSystem *input = game->input;
  if (!input)
    return;

  // Handle global input actions here
  // For example, toggling debug overlay
  if (input_action_pressed(input, INPUT_KEY_DEBUG_TOGGLE))
  {
    handle_debug_toggle(game);
  }
}