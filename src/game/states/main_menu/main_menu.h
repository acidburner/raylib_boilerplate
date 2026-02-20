#pragma once

#include <raylib.h>
#include "game/game.h"

typedef struct Game Game; // Forward declaration

typedef enum MainMenuOption {
    MAIN_MENU_OPTION_START_GAME,
    MAIN_MENU_OPTION_SETTINGS,
    MAIN_MENU_OPTION_EXIT,
    MAIN_MENU_OPTION_COUNT
} MainMenuOption;

// main menu options
extern const char* MAIN_MENU_OPTIONS[MAIN_MENU_OPTION_COUNT];
extern const Vector2 MAIN_MENU_OPTION_POSITIONS[MAIN_MENU_OPTION_COUNT];
//state functions
void menu_enter(Game *game);
void menu_update(Game *game);
void menu_render(Game *game);
void menu_exit(Game *game);