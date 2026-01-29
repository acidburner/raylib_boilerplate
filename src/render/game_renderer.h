#pragma once

#include "render_api.h"

typedef struct GameRender {
    RenderAPI *api;
    void *impl; // Pointer to renderer-specific implementation data
} GameRender;

GameRender initGameRender(RenderAPI *api, void *impl);