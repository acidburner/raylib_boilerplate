#include "game/states.h"
#include "game/game.h"

#include "core/log/log.h"

void handle_pause(Game *game)
{
  LOG_INFO("Pause action triggered");
  update_game_state(game, GAME_STATE_PAUSED);
}