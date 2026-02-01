#include "boot.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include <raylib.h>
// boot
void boot_enter(Game *game)
{
  LOG_INFO("Entering Boot State");
  // draw loading screen or perform initial setup here
  // WaitTime(1.0); // Simulate loading time
}
void boot_update(Game *game)
{
  // Perform boot operations, loading resources, etc.
  LOG_INFO("Updating Boot State, delta time: %f", game->delta_time);
}
void boot_render(Game *game)
{
  // Render boot state visuals if any
  ClearBackground(BLACK);
  DrawText("Booting...", 20, 20, 20, WHITE);
}
void boot_exit(Game *game)
{
  // Cleanup boot state resources if any
  LOG_INFO("Exiting Boot State");
  WaitTime(0.5); // Simulate cleanup time
  // update to main menu
  update_game_state(game, GAME_STATE_MAIN_MENU);
}