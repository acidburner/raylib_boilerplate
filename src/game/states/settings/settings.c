#include "settings.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include "input_handlers/settings_input.h"
// settings

const char *SETTINGS_MENU_OPTIONS[SETTINGS_MENU_OPTION_COUNT] = {
    "Audio",
    "Video",
    "Controls",
    "Back"};


const Vector2 SETTINGS_MENU_OPTION_POSITIONS[SETTINGS_MENU_OPTION_COUNT] = {
    {50, 100},
    {50, 130},
    {50, 160},
    {50, 190}};

static SettingsMenuOption current_selection = SETTINGS_MENU_OPTION_AUDIO;

void settings_enter(Game *game)
{
  LOG_INFO("Entering Settings State");
}
void settings_update(Game *game)
{
  handle_settings_input(game, &current_selection);
}
void settings_render(Game *game)
{
  // Render settings state visuals here
  ClearBackground((Color){0, 128, 128, 255}); // Teal background
  DrawText("Settings State", 20, 20, 20, WHITE);
  for (int i = 0; i < SETTINGS_MENU_OPTION_COUNT; i++)
  {
    DrawText(SETTINGS_MENU_OPTIONS[i], SETTINGS_MENU_OPTION_POSITIONS[i].x, SETTINGS_MENU_OPTION_POSITIONS[i].y, 20, WHITE);
  }
  // draw highlight for current selection
  Vector2 highlight_pos = SETTINGS_MENU_OPTION_POSITIONS[current_selection];
  DrawRectangleLines(highlight_pos.x - 10, highlight_pos.y - 5, 150, 30, RED);
}
void settings_exit(Game *game)
{
  LOG_INFO("Exiting Settings State");
}