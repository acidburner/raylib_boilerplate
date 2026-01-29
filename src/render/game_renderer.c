
#include "game_renderer.h"

#pragma once
GameRender initGameRender(RenderAPI *api, void *impl) {
    GameRender renderer;
    renderer.api = api;
    renderer.impl = impl;
    return renderer;
}