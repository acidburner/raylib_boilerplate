#pragma once

#include "input/input.h"

typedef struct KeybindsMap
{
  const char *name;
  PhysicalKeysInput keys; // up to 4 physical keys per action
} KeybindsMap;

static const KeybindsMap DEFAULT_KEYBINDS_MAP[] = {
    {"MOVE_UP", PHYS_KEYBOARD_KEY_W},
    {"MOVE_DOWN", PHYS_KEYBOARD_KEY_S},
    {"MOVE_LEFT", PHYS_KEYBOARD_KEY_A},
    {"MOVE_RIGHT", PHYS_KEYBOARD_KEY_D},
    {"INTERACT", PHYS_KEYBOARD_KEY_E},
    {"PAUSE", PHYS_KEYBOARD_KEY_ESCAPE},
    {"DEBUG_TOGGLE", PHYS_KEYBOARD_KEY_F1},
    // add more keybinds as needed
    // mouse
    // gamepad
};