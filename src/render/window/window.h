// window.h
// raylib boilerplate
// Created by acidburner on 2024-04-15
//

//This file defines window parameters and settings.
// set/get window settings
// query window state
#pragma once

#include <stdbool.h>

typedef struct window {
    int width;
    int height;
    const char* title;
    int target_fps;
    bool fullscreen;
    bool resizable;
    bool borderless;
    bool vsync;
    // todo: add more window parameters as needed
} Window;

// Function prototypes for window management
void window_set_size(Window* window, int width, int height);
// void window_get_size(const Window* window);
void window_set_title(Window* window, const char* title);
const char* window_get_title(const Window* window);
bool window_is_fullscreen(const Window* window);
void window_toggle_fullscreen(Window* window);
// etc.