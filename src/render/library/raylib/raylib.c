// render/render_raylib.c
#include <raylib.h>
#include <render/render_api.h>

static void rl_initWindow(int w, int h, const char *title)
{
    InitWindow(w, h, title);
    SetTargetFPS(60); // ToDo: pass an options parameter such as {window: {width, height}, configuration: {fps: ...}} etc.
}

static void rl_shutdown(void)
{
    CloseWindow();
}

static void rl_begin(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
}

static void rl_end(void)
{
    EndDrawing();
}

static void rl_draw_text(const char *text, int x, int y, int size, Color color)
{
    DrawText(text, x, y, size, color);
}

static void rl_clear(float r, float g, float b, float a)
{
    ClearBackground((Color){
        (unsigned char)(r * 255),
        (unsigned char)(g * 255),
        (unsigned char)(b * 255),
        (unsigned char)(a * 255),
    });
}

static bool rl_windowShouldClose(void)
{
    return WindowShouldClose();
}

static void rl_draw_rectangle(int x, int y, int width, int height, Color color)
{
    DrawRectangle(x, y, width, height, color);
}

static void rl_draw_rectangle_lines(int x, int y, int width, int height, Color color)
{
    DrawRectangleLines(x, y, width, height, color);
}

static void rl_draw_line(int x1, int y1, int x2, int y2, Color color)
{
    DrawLine(x1, y1, x2, y2, color);
}

static void rl_draw_circle(int centerX, int centerY, float radius, Color color)
{
    DrawCircle(centerX, centerY, radius, color);
}

const RenderAPI RAYLIB_RENDER_API = {
    .initWindow = rl_initWindow,
    .shutdown = rl_shutdown,
    .begin_frame = rl_begin,
    .end_frame = rl_end,
    .draw_text = rl_draw_text,
    .draw_rectangle = rl_draw_rectangle,
    .draw_rectangle_lines = rl_draw_rectangle_lines,
    .draw_line = rl_draw_line,
    .draw_circle = rl_draw_circle,
    .clear = rl_clear,
    .window_should_close = rl_windowShouldClose,
};