#include "press_any_key.h"

#include <raylib.h>

void handle_press_any_key(Game *game) {
  // ToDo: (raylib GetKeyPressed) should be the input api system, but okay for now
    if(GetKeyPressed() != 0) {
      update_game_state(game, GAME_STATE_MAIN_MENU);
    }
    return; // No key pressed

}