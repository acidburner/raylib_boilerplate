#include "window.h"
#include "stdbool.h"
#include "stddef.h"

void window_set_size(Window* window, int width, int height) {
    if (window) {
        window->width = width;
        window->height = height;
    }
}

// void window_get_size(const Window* window) {
//     if (window) {
//       return {window->width, window->height};
//     }
//     return {0, 0};
// }

void window_set_title(Window* window, const char* title) {
  // assert(title != NULL);
    if (window) {
        window->title = title;
    }
}

const char* window_get_title(const Window* window) {
    if (window) {
        return window->title;
    }
    return NULL;
}

bool window_is_fullscreen(const Window* window) {
    if (window) {
        return window->fullscreen;
    }
    return false;
}

void window_toggle_fullscreen(Window* window) {
    if (window) {
        window->fullscreen = !window->fullscreen;
    }
}