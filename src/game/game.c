// core
#include "core/log/log.h"
#include "core/panic.h"
#include "clock/timer.h"
// input
#include "input/input.h"
#include "input/platform/input_raylib.h"
#include "input/input.h"
// render
#include "render/debug_overlay/debug_overlay.h"
// game
#include "game.h"
// std libs
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


#define LOG_CATEGORY "Game"

//Todo: make configurable
// todo: only error and fatal in release builds
#define LOG_MASK (LOG_MASK_ALL)
// #define LOG_MASK (LOG_MASK_TRACE | LOG_MASK_DEBUG | LOG_MASK_INFO | LOG_MASK_WARNING | LOG_MASK_ERROR | LOG_MASK_FATAL)

Game* game_create(RenderAPI *render_api, PlatformInputAPI *platform_input_api, LogApi *logger) {
    Game* game = (Game*)malloc(sizeof(Game));
    // set initial states
    game->currentState = GAME_STATE_INVALID;
    game->previousState = GAME_STATE_INVALID;
    if (game) {
        game->settings = (Settings){
            .window_width = 800,
            .window_height = 600,
            .fullscreen = false,
            .master_volume = 1.0f,
            .music_volume = 0.8f,
            .sfx_volume = 0.8f
        }; // ToDo: load default settings, or from file
        game->renderer = (GameRender*)malloc(sizeof(GameRender));
        if (game->renderer) {
            *(game->renderer) = initGameRender(render_api, NULL);
        }
        game->input = (InputSystem*)malloc(sizeof(InputSystem));
        if (!game->input)
        {
            PANIC("Failed to allocate InputSystem");
        }

        memset(game->input, 0, sizeof(InputSystem));
        load_default_input_bindings(&game->input->bindings);
        game->input->platform = platform_input_api;
        game->logger = logger;
        if(game->logger && game->logger->init) {
            game->logger->init(NULL, LOG_MASK, 1);
        }
        LOG_INFO("Logger initialized");
        game->is_running = true;
        game->debug_overlay_enabled = false;
        game->delta_time = 0.0;
        game->last_delta_time = 0.0;
    }
    LOG_DEBUG("Game initialized v%s", GAME_VERSION);
    return game;
}

void game_destroy(Game *game) {
    if(!game) {
        return;
    }
    if (game->renderer) {
        game->renderer->api->shutdown();
        free(game->renderer);
    }
    if(game->logger && game->logger->shutdown) {
        game->logger->shutdown();
    }
    if(game->input) {
        free(game->input);
    }
    free(game);
}

void game_init(Game *game) {
    if (game && game->renderer && game->renderer->api) {
        // Initialize renderer window
        game->renderer->api->initWindow(
            game->settings.window_width,
            game->settings.window_height,
            GAME_NAME
        );
    }
    // Load assets, initialize game state, etc.
    // update_game_state(game, GAME_STATE_MENU);
    LOG_INFO("Game initialized.");
}

void game_shutdown(Game *game) {
    if (game) {
        game->is_running = false;
        update_game_state(game, GAME_STATE_SHUTDOWN);
    }
    LOG_INFO("Game shutting down...");
}

void game_start(Game *game) {
    LOG_INFO("Game loop started...");
    update_game_state(game, GAME_STATE_BOOT);

    game->is_running = true;
    game->last_delta_time = get_platform_time_now();
    while(game->is_running) {
        if(game->renderer->api->window_should_close()) {
            game_shutdown(game);
            break;
        }
        game->renderer->api->begin_frame();
        game_tick(game);
        if(game->debug_overlay_enabled) {
            debug_overlay_render(game);
        }
        game->renderer->api->end_frame();
    }
    LOG_INFO("Game loop ended.");
}

void game_update_running(Game *game) {
    LOG_INFO("Game is running. Delta time: %f", game->delta_time);
}

void game_update_menu(Game *game) {
    LOG_INFO("In Menu State. Delta time: %f", game->delta_time);
}

void game_update_paused(Game *game) {
    LOG_INFO("Game is paused. Delta time: %f", game->delta_time);
}

void game_update_shutdown(Game *game) {
    LOG_INFO("Game is shutting down. Delta time: %f", game->delta_time);
    game_shutdown(game);
}

void game_tick(Game *game) {
    double now = get_platform_time_now();
    game->delta_time = get_platform_time_delta(game->last_delta_time, now);
    game->last_delta_time = now;
    const GameStateVTable *table = get_game_state_vtable();
    if( table[game->currentState].update ) {
        table[game->currentState].update(game);
    }
    // Placeholder for game tick logic
    // Update game state, handle inputs, render frame, etc.
}
