#include "paused.h"
#include "game/game.h"
#include "core/log/log.h"

#include "game/states.h"

#include "input_handlers/paused_input.h"

#include <raylib.h>

const char *PAUSED_MENU_OPTIONS[PAUSED_MENU_OPTION_COUNT] = {
    "Resume Game",
    "Settings",
    "Exit"};

const Vector2 PAUSED_MENU_OPTION_POSITIONS[PAUSED_MENU_OPTION_COUNT] = {
    {50, 100},
    {50, 130},
    {50, 160}};

static PausedMenuOption current_selection = PAUSED_MENU_OPTION_RESUME;

// paused
void paused_enter(Game *game)
{
  LOG_INFO("Entering Paused State");
}
void paused_update(Game *game)
{
  handle_paused_input(game, &current_selection);
}
void paused_render(Game *game)
{
  // Render paused state visuals here
  ClearBackground((Color){128, 128, 128, 255}); // Gray background
  DrawText("Paused State", 20, 20, 20, WHITE);
  for(int i = 0; i < PAUSED_MENU_OPTION_COUNT; i++) {
    DrawText(PAUSED_MENU_OPTIONS[i], PAUSED_MENU_OPTION_POSITIONS[i].x, PAUSED_MENU_OPTION_POSITIONS[i].y, 20, WHITE);
  }
  // draw highlight for current selection
  Vector2 highlight_pos = PAUSED_MENU_OPTION_POSITIONS[current_selection];
  DrawRectangleLines(highlight_pos.x - 10, highlight_pos.y - 5, 150, 30, RED);
}
void paused_exit(Game *game)
{
  LOG_INFO("Exiting Paused State");
}