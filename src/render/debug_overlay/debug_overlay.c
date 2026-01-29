
#include "debug_overlay.h"
#include "render/game_renderer.h"

#include <stdio.h>

void debug_overlay_render(Game *game) {
  RenderAPI *api = game->renderer->api;

  //draw overlay background
  api->draw_rectangle(5, 5, 200, 200, (Color){0, 0, 0, 128});
  //draw border
  api->draw_rectangle_lines(5, 5, 200, 200, (Color){255, 255, 255, 255});
    //draw foreground (if required)
    //draw text
    api->draw_text("Debug Overlay", 10, 10, 20, (Color){255, 0, 0, 255});
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "FPS: %d", GetFPS());
    api->draw_text(buffer, 10, 40, 16, (Color){255, 255, 255, 255});
    snprintf(buffer, sizeof(buffer), "Delta Time: %.3f ms", game->delta_time * 1000.0);
    api->draw_text(buffer, 10, 60, 16, (Color){255, 255, 255, 255});
  }