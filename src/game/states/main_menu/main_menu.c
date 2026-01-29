#include "main_menu.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

// menu
void menu_enter(Game *game)
{
  LOG_INFO("Entering Menu State");
}
void menu_update(Game *game)
{
  LOG_INFO("Updating Menu State, delta time: %f", game->delta_time);
  update_game_state(game, GAME_STATE_PLAYING);
}
void menu_exit(Game *game)
{
  LOG_INFO("Exiting Menu State");
}