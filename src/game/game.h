// handles game state, main loop, initialization, shutdown
#pragma once
#include "states.h"
#include "settings/settings.h"
#include "render/game_renderer.h"
#include "input/input.h"
#include "core/log/log_api.h"
#include "world/world.h"

// Game definitions
#define GAME_NAME "raylib boilerplate"
#define GAME_VERSION "0.1.0"

// Game tick rate definitions
#define GAME_TICK_RATE 60.0
#define GAME_TICK_DURATION (1.0 / GAME_TICK_RATE)

//Game forward declarations
typedef struct Game Game;

// Game structure
//
typedef struct Game {
    // add game-related members here
    GameState currentState;
    GameState previousState;
    Settings settings;
    GameRender *renderer;
    InputSystem *input;
    LogApi *logger;
    World *world;
    bool is_running;
    double delta_time;
    double last_delta_time;
    // etc.

    // game flags
    bool debug_overlay_enabled;
} Game;

// Function prototypes
Game* game_create(RenderAPI *render_api, PlatformInputAPI *platform_input_api, LogApi *logger);
void game_destroy(Game *game);
void game_init(Game *game);
void game_start(Game *game);
void game_shutdown(Game *game);
void game_tick(Game *game);