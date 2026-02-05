// responsibilities
// - Load from disk at startup
// - Hold current settings in memory
// - Be mutable at runtime
// - Save back to disk

    // ToDo

#pragma once

#include "input/input.h"
#include "keybinds.h"

#include <stdbool.h>


typedef struct Settings {
    int window_width;
    int window_height;
    bool fullscreen;
    float master_volume;
    float music_volume;
    float sfx_volume;
    KeybindsMap keybinds;
    char * fontPath;
    // add more settings as needed
} Settings;

void settings_load(Settings* settings, const char* filepath);
void settings_save(const Settings* settings, const char* filepath);
void settings_apply(const Settings* settings);
void settings_reset_to_defaults(Settings* settings);
Settings settings_get_default(void);