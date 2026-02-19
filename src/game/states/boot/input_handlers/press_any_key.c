#include "press_any_key.h"
#include "core/log/log.h"

#include "input/platform/input_raylib_helpers.h"

void handle_press_any_key(Game *game) {
  // ToDo: (raylib GetKeyPressed) should be the input api system, but okay for now
    if(is_any_key_pressed()) {
      LOG_INFO("Key pressed, transitioning to Main Menu");
      update_game_state(game, GAME_STATE_MAIN_MENU);
    }
    return; // No key pressed

} // ToDo: (raylib GetKeyPressed) should be the input api system, but okay for now
