#include "menu_input.h"
#include "game/states/main_menu/main_menu.h"
#include "input/input.h"
#include "core/log/log.h"

void handle_menu_input(Game *game, MenuOption *current_selection) {
  // use input api to check for key presses and update menu selection
  // use mouse input to highlight and select menu options
  // ToDo: implement menu navigation and selection logic based on input
  if(!game->input) {
    return;
  }
  // Example: Check for up/down arrow keys to navigate menu options
  if (input_action_pressed(game->input, INPUT_KEY_MOVE_UP)) {
    // Move selection up
    LOG_INFO("Menu Input: Move Up");
    if(*current_selection == 0) {
      *current_selection = MENU_OPTION_COUNT - 1; // wrap around to last option
    } else {
      (*current_selection)--;
    }

  }
  else if (input_action_pressed(game->input, INPUT_KEY_MOVE_DOWN)) {
    // Move selection down
    LOG_INFO("Menu Input: Move Down");
    if(*current_selection == MENU_OPTION_COUNT - 1) {
      *current_selection = 0; // wrap around to first option
    } else {
      (*current_selection)++;
    }
  }
  else if (input_action_pressed(game->input, INPUT_KEY_INTERACT)) {
    // Select current menu option
    LOG_INFO("Menu Input: Interact/Select");
    switch (*current_selection) {
      case MENU_OPTION_START_GAME:
        LOG_INFO("Selected: Start Game");
        update_game_state(game, GAME_STATE_PLAYING);
        break;
      case MENU_OPTION_SETTINGS:
        LOG_INFO("Selected: Settings");
        update_game_state(game, GAME_STATE_SETTINGS);
        break;
      case MENU_OPTION_EXIT:
        LOG_INFO("Selected: Exit");
        update_game_state(game, GAME_STATE_SHUTDOWN);
        break;
      default:
        break;
    }
  } else {
    // Check for mouse input to highlight/select options
  }
}