#include "settings.h"
#include <stdbool.h>
#include "core/panic.h"

#define DEFAULT_SETTINGS { \
    .window_width = 800, \
    .window_height = 600, \
    .fullscreen = false, \
    .master_volume = 1.0f, \
    .music_volume = 0.8f, \
    .sfx_volume = 0.8f, \
    /* add more default settings as needed */ \
}

// Load settings from a file
void settings_load(Settings* settings, const char* filepath) {
  //ToDo
  NOT_IMPLEMENTED();
}

void settings_save(const Settings* settings, const char* filepath) {
  //ToDo
  NOT_IMPLEMENTED();
}

void settings_apply(const Settings* settings) {
  //ToDo
  NOT_IMPLEMENTED();
}

Settings settings_get_default(void) {
    Settings default_settings = DEFAULT_SETTINGS;
    return default_settings;
}

void settings_reset_to_defaults(Settings* settings) {
    if (settings) {
        *settings = settings_get_default();
    }
}