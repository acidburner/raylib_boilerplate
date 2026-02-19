#pragma once

#include <raylib.h>
#include "game/game.h"

typedef struct Game Game; // Forward declaration

typedef enum MenuOption {
    MENU_OPTION_START_GAME,
    MENU_OPTION_SETTINGS,
    MENU_OPTION_EXIT,
    MENU_OPTION_COUNT
} MenuOption;

// main menu options
extern const char* MENU_OPTIONS[MENU_OPTION_COUNT];
extern const Vector2 MENU_OPTION_POSITIONS[MENU_OPTION_COUNT];
//state functions
void menu_enter(Game *game);
void menu_update(Game *game);
void menu_render(Game *game);
void menu_exit(Game *game);