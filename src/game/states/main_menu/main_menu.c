#include "main_menu.h"
#include "input_handlers/menu_input.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include <raylib.h>

const char *MAIN_MENU_OPTIONS[MAIN_MENU_OPTION_COUNT] = {
    "Start Game",
    "Settings",
    "Exit"
  };

const Vector2 MAIN_MENU_OPTION_POSITIONS[MAIN_MENU_OPTION_COUNT] = {
    {50, 100},
    {50, 130},
    {50, 160}
};

static MainMenuOption current_selection = MAIN_MENU_OPTION_START_GAME;

// menu
void menu_enter(Game *game)
{
  LOG_INFO("Entering Menu State");
  current_selection = MAIN_MENU_OPTION_START_GAME; // reset selection when entering menu

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
  // ToDo use game->renderer api to draw menu screen, should be a call to game->renderer->api->DrawMenu or something similar that handles drawing the menu background, options, and highlights based on current selection
  DrawText("Raylib Boilerplate", 20, 20, 20, WHITE);
  for(int i = 0; i < MAIN_MENU_OPTION_COUNT; i++) {
    DrawText(MAIN_MENU_OPTIONS[i], MAIN_MENU_OPTION_POSITIONS[i].x, MAIN_MENU_OPTION_POSITIONS[i].y, 20, WHITE);
  }
  // draw highlight for current selection
  Vector2 highlight_pos = MAIN_MENU_OPTION_POSITIONS[current_selection];
  DrawRectangleLines(highlight_pos.x - 10, highlight_pos.y - 5, 150, 30, RED);
}
void menu_exit(Game *game)
{
  LOG_INFO("Exiting Menu State");
}