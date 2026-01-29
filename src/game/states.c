#include "states.h"
#include "game.h"
#include "core/panic.h"
#include "core/log/log.h"

// state includes
#include "states/boot/boot.h"
#include "states/main_menu/main_menu.h"
#include "states/in_game/in_game.h"
#include "states/paused/paused.h"
#include "states/settings/settings.h"
#include "states/shutdown/shutdown.h"

#define LOG_CATEGORY "GameState"



//settings

// etc. for other states

// vtable

typedef struct GameStateVTable GameStateVTable;

static GameStateVTable gameStateTable[GAME_STATE_COUNT] = {
    [GAME_STATE_BOOT] = {
        .enter = boot_enter,
        .update = boot_update,
        .exit = boot_exit
    }, // implement boot state handlers
    [GAME_STATE_MENU] = {
        .enter = menu_enter,
        .update = menu_update,
        .exit = menu_exit
    },
    [GAME_STATE_SETTINGS] = {
        .enter = settings_enter,
        .update = settings_update,
        .exit = settings_exit
    }, // implement settings state handlers
    [GAME_STATE_PLAYING] = {
        .enter = in_game_enter,
        .update = in_game_update,
        .exit = in_game_exit
    }, // implement playing state handlers
    [GAME_STATE_PAUSED] = {
        .enter = paused_enter,
        .update = paused_update,
        .exit = paused_exit
    }, // implement paused state handlers
    [GAME_STATE_SHUTDOWN] = {
        .enter = shutdown_enter,
        .update = shutdown_update,
        .exit = shutdown_exit
    }, // implement shutdown state handlers
};

GameState get_game_state(Game *game) {
    if (!game) {
        PANIC("get_game_state: game is NULL");
    }
    return game->currentState;
}

void update_game_state(Game *game, GameState newState) {
    if (!game) {
        PANIC("set_game_state: game is NULL");
    }
    if (game->currentState >= GAME_STATE_COUNT ||
        newState >= GAME_STATE_COUNT)
    {
        PANIC("Invalid game state transition");
        exit(1);
    }

    const GameStateVTable *table = get_game_state_vtable();

    game->previousState = game->currentState;
    if(game->currentState != GAME_STATE_INVALID) {
        if( table[game->previousState].exit ) {
            table[game->previousState].exit(game);
        }
    }
    game->currentState = newState;
    if( table[game->currentState].enter ) {
        table[game->currentState].enter(game);
    }

}

const GameStateVTable* get_game_state_vtable(void) {
    return gameStateTable;
}