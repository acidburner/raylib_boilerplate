#include "paused.h"
#include "game/game.h"
#include "core/log/log.h"

#include "game/states.h"

// paused
void paused_enter(Game *game)
{
  LOG_INFO("Entering Paused State");
}
void paused_update(Game *game)
{
  LOG_INFO("Updating Paused State, delta time: %f", game->delta_time);
  update_game_state(game, GAME_STATE_SETTINGS);
}
void paused_exit(Game *game)
{
  LOG_INFO("Exiting Paused State");
}