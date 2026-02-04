#include "boot.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include <raylib.h>

// inputs
#include "input_handlers/press_any_key.h"
// boot

#define PRESS_ANY_KEY_TEXT "Press Any Key"
void boot_enter(Game *game)
{
  LOG_INFO("Entering Boot State");
  // draw loading screen or perform initial setup here
  // WaitTime(1.0); // Simulate loading time
}
void boot_update(Game *game)
{
  // Perform boot operations, loading resources, etc.
  handle_press_any_key(game);
}
void boot_render(Game *game)
{
  // Render boot state visuals if any
  // LOG_INFO("Rendering Boot State");
  // ToDo use game->renderer api to draw boot screen
  ClearBackground(BLACK);
  DrawText("Booting...", 20, 20, 20, WHITE);
  DrawRectangleLines(45, 90, 160, 40, RED);
  DrawText(PRESS_ANY_KEY_TEXT, 50, 100, 20, WHITE);
}
void boot_exit(Game *game)
{
  // Cleanup boot state resources if any
  LOG_INFO("Exiting Boot State");
}