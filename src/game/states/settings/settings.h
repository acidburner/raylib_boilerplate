#pragma once

#include <raylib.h>

typedef struct Game Game; // Forward declaration

typedef enum SettingsMenuOption {
    SETTINGS_MENU_OPTION_AUDIO,
    SETTINGS_MENU_OPTION_VIDEO,
    SETTINGS_MENU_OPTION_CONTROLS,
    SETTINGS_MENU_OPTION_BACK,
    SETTINGS_MENU_OPTION_COUNT
} SettingsMenuOption;

extern const char* SETTINGS_MENU_OPTIONS[SETTINGS_MENU_OPTION_COUNT];
extern const Vector2 SETTINGS_MENU_OPTION_POSITIONS[SETTINGS_MENU_OPTION_COUNT];

void settings_enter(Game *game);
void settings_update(Game *game);
void settings_render(Game *game);
void settings_exit(Game *game);