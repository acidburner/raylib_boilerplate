void handle_debug_toggle(Game *game)
{
  game->debug_overlay_enabled = !game->debug_overlay_enabled;
  LOG_INFO("Debug overlay toggled: %s", game->debug_overlay_enabled ? "ON" : "OFF");
}