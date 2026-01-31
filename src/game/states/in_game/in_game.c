#include "in_game.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include "game/states/input_dispatch_handler.h"
#include "in_game_state_dispatch.h"

// in_game
void in_game_enter(Game *game)
{
  LOG_INFO("Entering In-Game State");
}
void in_game_update(Game *game)
{
  if (game->input)
  {
    HandleGameDispatch(game);
    // if (input_action_pressed(game->input, INPUT_KEY_PAUSE))
    // {
    //   update_game_state(game, GAME_STATE_PAUSED);
    // }
    // if (input_action_pressed(game->input, INPUT_KEY_DEBUG_TOGGLE))
    // {
    //   game->debug_overlay_enabled = !game->debug_overlay_enabled;
    //   LOG_INFO("Debug overlay toggled: %s", game->debug_overlay_enabled ? "ON" : "OFF");
    // }
  }
}
void in_game_exit(Game *game)
{
  LOG_INFO("Exiting In-Game State");
}