#include "in_game.h"
#include "game/game.h"
#include "core/log/log.h"
#include "game/states.h"

#include "game/input_dispatch_handler.h"
#include "in_game_state_dispatch.h"

// in_game
void in_game_enter(Game *game)
{
  LOG_INFO("Entering In-Game State");
}
void in_game_update(Game *game)
{
  HandleGameDispatch(game);
}
void in_game_render(Game *game)
{
  // Render in-game visuals here
  ClearBackground((Color){100, 149, 237, 255}); // Cornflower Blue
  DrawText("In-Game State", 20, 20, 20, WHITE);
}
void in_game_exit(Game *game)
{
  LOG_INFO("Exiting In-Game State");
}