#pragma once

#include "game/game.h"

// Handles graphics math
// mostly used for ui elements like centering, padding, gaps, tiling, etc.

// ToDos
//

void center_rectangle(float containerX, float containerY, float containerWidth, float containerHeight,
                      float rectWidth, float rectHeight,
                      float *outX, float *outY);