#include "settings_input.h"
#include "game/states/settings/settings.h"
#include "input/input.h"
#include "core/log/log.h"

// ToDo: refactor MainMenu with Settings menu as there is overlap in functionality and structure, we can create a generic MenuState that both MainMenu and SettingsMenu can utilize to reduce code duplication and improve maintainability. This would involve abstracting common menu behaviors such as navigation, selection, and rendering into a base MenuState structure and then having specific implementations for MainMenu and SettingsMenu that define their unique options and actions.
void handle_settings_input(Game *game, SettingsMenuOption *current_selection)
{
  // use input api to check for key presses and update menu selection
  // use mouse input to highlight and select menu options
  // ToDo: implement menu navigation and selection logic based on input
  if (!game->input)
  {
    return;
  }
  // Example: Check for up/down arrow keys to navigate menu options
  if (input_action_pressed(game->input, INPUT_KEY_MOVE_UP))
  {
    // Move selection up
    LOG_INFO("Menu Input: Move Up");
    if (*current_selection == 0)
    {
      *current_selection = SETTINGS_MENU_OPTION_COUNT - 1; // wrap around to last option
    }
    else
    {
      (*current_selection)--;
    }
  }
  else if (input_action_pressed(game->input, INPUT_KEY_MOVE_DOWN))
  {
    // Move selection down
    LOG_INFO("Menu Input: Move Down");
    if (*current_selection == SETTINGS_MENU_OPTION_COUNT - 1)
    {
      *current_selection = 0; // wrap around to first option
    }
    else
    {
      (*current_selection)++;
    }
  }
  else if (input_action_pressed(game->input, INPUT_KEY_INTERACT))
  {
    // Select current menu option
    LOG_INFO("Menu Input: Interact/Select");
    switch (*current_selection)
    {
    case SETTINGS_MENU_OPTION_AUDIO:
      LOG_INFO("Selected: Audio");
      // ToDo: Implement audio settings
      break;
    case SETTINGS_MENU_OPTION_VIDEO:
      LOG_INFO("Selected: Video");
      // ToDo: Implement video settings
      break;
    case SETTINGS_MENU_OPTION_CONTROLS:
      LOG_INFO("Selected: Controls");
      // ToDo: Implement controls settings
      break;
    case SETTINGS_MENU_OPTION_BACK:
      LOG_INFO("Selected: Back");
      // todo should have a previous menu state to return to, rather than hardcoding main menu here
      update_game_state(game, game->previousState);
      break;
    default:
      break;
    }
  }
  else
  {
    // Check for mouse input to highlight/select options
  }
}