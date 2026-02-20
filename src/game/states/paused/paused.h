#pragma once

#include <raylib.h>

typedef struct Game Game; // Forward declaration

typedef enum PausedMenuOption {
    PAUSED_MENU_OPTION_RESUME,
    PAUSED_MENU_OPTION_SETTINGS,
    PAUSED_MENU_OPTION_EXIT,
    PAUSED_MENU_OPTION_COUNT
} PausedMenuOption;

extern const char* PAUSED_MENU_OPTIONS[PAUSED_MENU_OPTION_COUNT];
extern const Vector2 PAUSED_MENU_OPTION_POSITIONS[PAUSED_MENU_OPTION_COUNT];

void paused_enter(Game *game);
void paused_update(Game *game);
void paused_render(Game *game);
void paused_exit(Game *game);