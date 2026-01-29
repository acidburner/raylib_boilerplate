#include "shutdown.h"
#include "game/game.h"
#include "core/log/log.h"

// shutdown
void shutdown_enter(Game *game)
{
  LOG_INFO("Entering Shutdown State");
}
void shutdown_update(Game *game)
{
  LOG_INFO("Updating Shutdown State, delta time: %f", game->delta_time);
  game->is_running = false;
}
void shutdown_exit(Game *game)
{
  LOG_INFO("Exiting Shutdown State");
}