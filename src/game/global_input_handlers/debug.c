#include "debug.h"
#include "core/log/log.h"
#include "global_input_handlers.h"

void handle_debug_toggle(Game *game)
{
  game->debug_overlay_enabled = !game->debug_overlay_enabled;
  LOG_INFO("Debug overlay toggled: %s", game->debug_overlay_enabled ? "ON" : "OFF");
}