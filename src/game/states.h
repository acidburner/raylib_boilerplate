#pragma once

typedef enum GameState
{
    GAME_STATE_INVALID = -1,
    GAME_STATE_BOOT,
    GAME_STATE_MENU,
    GAME_STATE_SETTINGS,
    GAME_STATE_PLAYING,
    GAME_STATE_PAUSED,
    GAME_STATE_SHUTDOWN,
    GAME_STATE_COUNT
} GameState;

typedef struct Game Game;

typedef struct GameStateVTable {
    void (*enter)(Game *game);
    void (*update)(Game *game);
    void (*exit)(Game *game);
} GameStateVTable;

void update_game_state(Game *game, GameState newState);
GameState get_game_state(Game *game);
const GameStateVTable* get_game_state_vtable(void);

