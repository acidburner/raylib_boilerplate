
#include "debug_overlay.h"
#include "render/game_renderer.h"

#include <stdio.h>

void debug_overlay_render(Game *game) {
  RenderAPI *api = game->renderer->api;

  int window_width = game->settings.window_width;
  int window_height = game->settings.window_height;

  // ToDo: create defines in header file
  int overlay_margin = 10;
  int text_margin = 10; // margin from window edges
  int padding_between_sections = 10; // vertical padding between sections of text
  // todo add margins/padding and tiling to dialog windows

  int overlay_width = window_width - overlay_margin * 2; // width includes margins on both sides
  int overlay_height = window_height / 2 -  overlay_margin * 2; // height includes margin at top and bottom, and takes up half the screen height

  int sub_height = 30;
  int sub_margin = text_margin + 20;

  int text_start_x = sub_margin; //start text at 20 pixels from the left edge of the window (10 pixels margin + 10 pixels padding)
  int text_start_y = sub_margin; //start text at 20 pixels from the top edge of the window (10 pixels margin + 10 pixels padding)

  // relative positions of x and y of text lines should be based on font size and line spacing, not hardcoded values
  int fps_start_x = text_start_x + sub_margin * 1.25; // 30 pixels to the right of the first line
  int fps_start_y = text_start_y + sub_height; // 30 pixels below the first

  int delta_time_start_x = fps_start_x;       // aligned with first line
  int delta_time_start_y = fps_start_y + sub_height; // 60 pixels below the first line

  int current_State_start_x = fps_start_x;       // aligned with first line
  int current_State_start_y = delta_time_start_y + sub_height; // 90 pixels below the first line

  int last_key_start_x = fps_start_x;        // aligned with first line
  int last_key_start_y = current_State_start_y + sub_height; // 120 pixels below the first line

  //font sizes
  int header_font_size = 20;
  int text_font_size = 16;

  //draw overlay background
  api->draw_rectangle(overlay_margin, overlay_margin, overlay_width, overlay_height, (Color){0, 0, 0, 225});
  //draw border
  api->draw_rectangle_lines(overlay_margin, overlay_margin, overlay_width, overlay_height, (Color){255, 255, 255, 255});
    //draw foreground (if required)
    //draw text
    api->draw_text("Debug Overlay", text_start_x, text_start_y, header_font_size, (Color){255, 0, 0, 255});
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "FPS: %d", GetFPS());
    api->draw_text(buffer, fps_start_x, fps_start_y, text_font_size, (Color){255, 255, 255, 255});
    snprintf(buffer, sizeof(buffer), "Delta Time: %.3f ms", game->delta_time * 1000.0);
    api->draw_text(buffer, delta_time_start_x, delta_time_start_y, text_font_size, (Color){255, 255, 255, 255});
    GameState state = game->currentState;
    //convert current state to string
    char * state_str = "TEST";
    snprintf(buffer, sizeof(buffer), "Current State: %s", state_str);
    api->draw_text(buffer, current_State_start_x, current_State_start_y, text_font_size, (Color){255, 255, 255, 255});
    //draw last key and character pressed
    PhysicalKeysInput last_key = game->input->bindings.last_key_used;
    // convert input to string representation
    snprintf(buffer, sizeof(buffer), "Last Key Pressed: %d", last_key);
    api->draw_text(buffer, last_key_start_x, last_key_start_y, text_font_size, (Color){255, 255, 255, 255});

  }