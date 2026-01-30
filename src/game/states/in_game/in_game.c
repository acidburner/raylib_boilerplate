#include "in_game.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

// in_game
void in_game_enter(Game *game)
{
  LOG_INFO("Entering In-Game State");
}
void in_game_update(Game *game)
{
  if (game->input)
  {
    // LOG_INFO("Checking input in In-Game State");
    if (input_action_pressed(game->input, INPUT_KEY_PAUSE))
    {
      LOG_INFO("Escape key pressed");
      update_game_state(game, GAME_STATE_PAUSED);
    }
    if (input_action_pressed(game->input, INPUT_KEY_DEBUG_TOGGLE))
    {
      game->debug_overlay_enabled = !game->debug_overlay_enabled;
      LOG_INFO("Debug overlay toggled: %s", game->debug_overlay_enabled ? "ON" : "OFF");
    }
  }
}
void in_game_exit(Game *game)
{
  LOG_INFO("Exiting In-Game State");
}