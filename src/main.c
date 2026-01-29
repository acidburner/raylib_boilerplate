#include "game/game.h"
#include "core/log/log.h"
#include "render/library/raylib/raylib.h"
#include "input/platform/input_raylib.h"
#include "core/log/library/slog/log.h"

#define LOG_CATEGORY "Main"

int main(void) {
    LOG_INFO("Starting %s", GAME_NAME);
    // create game with Raylib renderer and SLOG logger
    Game *game = game_create(&RAYLIB_RENDER_API, &RAYLIB_INPUT_API, &SLOG_LOG_API);
    //initialize game and load assets
    game_init(game);
    //start game loop
    game_start(game);
    //shutdown game and free resources
    game_destroy(game);
    LOG_INFO("Exiting %s", GAME_NAME);
    return 0;
}