#include "settings.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"
// settings
void settings_enter(Game *game)
{
  LOG_INFO("Entering Settings State");
}
void settings_update(Game *game)
{
  LOG_INFO("Updating Settings State, delta time: %f", game->delta_time);
  update_game_state(game, GAME_STATE_SHUTDOWN);
}
void settings_exit(Game *game)
{
  LOG_INFO("Exiting Settings State");
}