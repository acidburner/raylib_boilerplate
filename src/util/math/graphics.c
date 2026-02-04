#include "graphics.h"

void center_rectangle(float containerX, float containerY, float containerWidth, float containerHeight,
                      float rectWidth, float rectHeight,
                      float *outX, float *outY) {
    if (outX) {
      // Center the rectangle within the container, centers based on midpoint of the rectangle
        *outX = containerX + (containerWidth - (rectWidth / 2.0f) ) / 2.0f;
    }
    if (outY) {
        *outY = containerY + (containerHeight - (rectHeight / 2.0f) ) / 2.0f;
    }
}