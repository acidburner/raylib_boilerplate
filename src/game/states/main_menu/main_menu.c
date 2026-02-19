#include "main_menu.h"
#include "input_handlers/menu_input.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include <raylib.h>

const char *MENU_OPTIONS[MENU_OPTION_COUNT] = {
    "Start Game",
    "Settings",
    "Exit"
  };

const Vector2 MENU_OPTION_POSITIONS[MENU_OPTION_COUNT] = {
    {50, 100},
    {50, 130},
    {50, 160}
};

static MenuOption current_selection = MENU_OPTION_START_GAME;

// menu
void menu_enter(Game *game)
{
  LOG_INFO("Entering Menu State");
  current_selection = MENU_OPTION_START_GAME; // reset selection when entering menu

}
void menu_update(Game *game)
{
  // Perform menu logic here
  handle_menu_input(game, &current_selection);
}
void menu_render(Game *game)
{
  // Render menu visuals here
  ClearBackground(BLUE);
  // ToDo use game->renderer api to draw menu screen
  // use MenuOption enum and MENU_OPTIONS array to render menu options
  DrawText("Raylib Boilerplate", 20, 20, 20, WHITE);
  for(int i = 0; i < MENU_OPTION_COUNT; i++) {
    DrawText(MENU_OPTIONS[i], MENU_OPTION_POSITIONS[i].x, MENU_OPTION_POSITIONS[i].y, 20, WHITE);
  }
  // draw highlight for current selection
  Vector2 highlight_pos = MENU_OPTION_POSITIONS[current_selection];
  DrawRectangleLines(highlight_pos.x - 10, highlight_pos.y - 5, 150, 30, RED);
}
void menu_exit(Game *game)
{
  LOG_INFO("Exiting Menu State");
}