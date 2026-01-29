#include "boot.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"
// boot
void boot_enter(Game *game)
{
  LOG_INFO("Entering Boot State");
}
void boot_update(Game *game)
{
  LOG_INFO("Updating Boot State, delta time: %f", game->delta_time);
  update_game_state(game, GAME_STATE_MENU);
}
void boot_exit(Game *game)
{
  LOG_INFO("Exiting Boot State");
}