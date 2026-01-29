// render/render_api.h
#pragma once

#include <stdbool.h>
#include <raylib.h>

// API wrapper to graphics libraries
typedef struct RenderAPI {
    void (*initWindow)(int w, int h, const char *title);
    void (*shutdown)(void);
    void (*begin_frame)(void);
    void (*end_frame)(void);
    void (*draw_rectangle)(int x, int y, int width, int height, Color color);
    void (*draw_rectangle_lines)(int x, int y, int width, int height, Color color);
    void (*draw_line)(int x1, int y1, int x2, int y2, Color color);
    void (*draw_circle)(int centerX, int centerY, float radius, Color color);
    void (*draw_text)(const char *text, int x, int y, int size, Color color);
    void (*clear)(float r, float g, float b, float a);
    bool (*window_should_close)(void);
} RenderAPI;

