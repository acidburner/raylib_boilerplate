#include "game/states.h"
#include "game/game.h"

void handle_pause(Game *game)
{
  update_game_state(game, GAME_STATE_PAUSED);
}