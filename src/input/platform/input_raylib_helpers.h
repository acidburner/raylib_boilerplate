// helper functions for grouping input-related code

#pragma once

#include "input/input.h"
#include <raylib.h>
#include <stdbool.h>

// input comparators for in-game actions
static inline bool move_up_pressed(void) {
    return IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP);
}

static inline bool move_down_pressed(void) {
    return IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
}

static inline bool move_left_pressed(void) {
    return IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
}

static inline bool move_right_pressed(void) {
    return IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
}

static inline bool interact_pressed(void) {
    return IsKeyPressed(KEY_E) || IsKeyPressed(KEY_ENTER)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
}

static inline bool pause_pressed(void) {
    return IsKeyPressed(KEY_ESCAPE)
    || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT);
}

static inline bool debug_toggle_pressed(void) {
    return IsKeyPressed(KEY_F1);
}

// physical key checkers
static inline bool is_key_pressed(PhysicalKeysInput key) {
    switch(key) {
        case PHYS_KEYBOARD_KEY_W:
            return IsKeyPressed(KEY_W);
        case PHYS_KEYBOARD_KEY_A:
            return IsKeyPressed(KEY_A);
        case PHYS_KEYBOARD_KEY_S:
            return IsKeyPressed(KEY_S);
        case PHYS_KEYBOARD_KEY_D:
            return IsKeyPressed(KEY_D);
        case PHYS_KEYBOARD_KEY_UP:
            return IsKeyPressed(KEY_UP);
        case PHYS_KEYBOARD_KEY_DOWN:
            return IsKeyPressed(KEY_DOWN);
        case PHYS_KEYBOARD_KEY_LEFT:
            return IsKeyPressed(KEY_LEFT);
        case PHYS_KEYBOARD_KEY_RIGHT:
            return IsKeyPressed(KEY_RIGHT);
        case PHYS_KEYBOARD_KEY_ESCAPE:
            return IsKeyPressed(KEY_ESCAPE);
        case PHYS_KEYBOARD_KEY_F1:
            return IsKeyPressed(KEY_F1);
        case PHYS_KEYBOARD_KEY_ENTER:
            return IsKeyPressed(KEY_ENTER);
        case PHYS_KEYBOARD_KEY_E:
            return IsKeyPressed(KEY_E);
        case PHYS_MOUSE_BUTTON_LEFT:
            return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        case PHYS_MOUSE_BUTTON_RIGHT:
            return IsMouseButtonPressed(MOUSE_BUTTON_RIGHT);
        case PHYS_MOUSE_BUTTON_MIDDLE:
            return IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE);
        case PHYS_MOUSE_BUTTON_SCROLL_UP:
            return GetMouseWheelMove() > 0;
        case PHYS_MOUSE_BUTTON_SCROLL_DOWN:
            return GetMouseWheelMove() < 0;
        case PHYS_MOUSE_BUTTON_FORWARD:
            return IsMouseButtonPressed(MOUSE_BUTTON_SIDE);
        case PHYS_MOUSE_BUTTON_BACK:
            return IsMouseButtonPressed(MOUSE_BUTTON_EXTRA);
        case PHYS_GAMEPAD_DPAD_UP:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP);
        case PHYS_GAMEPAD_DPAD_DOWN:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        case PHYS_GAMEPAD_DPAD_LEFT:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        case PHYS_GAMEPAD_DPAD_RIGHT:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        case PHYS_GAMEPAD_BUTTON_A:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
        case PHYS_GAMEPAD_BUTTON_B:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
        case PHYS_GAMEPAD_BUTTON_X:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
        case PHYS_GAMEPAD_BUTTON_Y:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_UP);
        case PHYS_GAMEPAD_SHOULDER_LEFT_TRIGGER:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1);
        case PHYS_GAMEPAD_SHOULDER_LEFT_BUMPER:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_TRIGGER_2);
        case PHYS_GAMEPAD_SHOULDER_RIGHT_TRIGGER:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
        case PHYS_GAMEPAD_SHOULDER_RIGHT_BUMPER:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2);
        case PHYS_GAMEPAD_BUTTON_BACK:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_LEFT);
        case PHYS_GAMEPAD_BUTTON_START:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT);
        case PHYS_GAMEPAD_THUMB_LEFT_CLICK:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_THUMB);
        case PHYS_GAMEPAD_THUMB_RIGHT_CLICK:
            return IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_THUMB);
        default:
            return false;
    }
}

static inline bool is_key_down(PhysicalKeysInput key) {
    switch(key) {
        case PHYS_KEYBOARD_KEY_W:
            return IsKeyDown(KEY_W);
        case PHYS_KEYBOARD_KEY_A:
            return IsKeyDown(KEY_A);
        case PHYS_KEYBOARD_KEY_S:
            return IsKeyDown(KEY_S);
        case PHYS_KEYBOARD_KEY_D:
            return IsKeyDown(KEY_D);
        case PHYS_KEYBOARD_KEY_UP:
            return IsKeyDown(KEY_UP);
        case PHYS_KEYBOARD_KEY_DOWN:
            return IsKeyDown(KEY_DOWN);
        case PHYS_KEYBOARD_KEY_LEFT:
            return IsKeyDown(KEY_LEFT);
        case PHYS_KEYBOARD_KEY_RIGHT:
            return IsKeyDown(KEY_RIGHT);
        case PHYS_KEYBOARD_KEY_ESCAPE:
            return IsKeyDown(KEY_ESCAPE);
        case PHYS_KEYBOARD_KEY_F1:
            return IsKeyDown(KEY_F1);
        case PHYS_KEYBOARD_KEY_ENTER:
            return IsKeyDown(KEY_ENTER);
        case PHYS_KEYBOARD_KEY_E:
            return IsKeyDown(KEY_E);
        case PHYS_MOUSE_BUTTON_LEFT:
            return IsMouseButtonDown(MOUSE_BUTTON_LEFT);
        case PHYS_MOUSE_BUTTON_RIGHT:
            return IsMouseButtonDown(MOUSE_BUTTON_RIGHT);
        case PHYS_MOUSE_BUTTON_MIDDLE:
            return IsMouseButtonDown(MOUSE_BUTTON_MIDDLE);
        case PHYS_MOUSE_BUTTON_SCROLL_UP:
            return GetMouseWheelMove() > 0;
        case PHYS_MOUSE_BUTTON_SCROLL_DOWN:
            return GetMouseWheelMove() < 0;
        case PHYS_MOUSE_BUTTON_FORWARD:
            return IsMouseButtonDown(MOUSE_BUTTON_SIDE);
        case PHYS_MOUSE_BUTTON_BACK:
            return IsMouseButtonDown(MOUSE_BUTTON_EXTRA);
        case PHYS_GAMEPAD_DPAD_UP:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP);
        case PHYS_GAMEPAD_DPAD_DOWN:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN);
        case PHYS_GAMEPAD_DPAD_LEFT:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT);
        case PHYS_GAMEPAD_DPAD_RIGHT:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
        case PHYS_GAMEPAD_BUTTON_A:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
        case PHYS_GAMEPAD_BUTTON_B:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
        case PHYS_GAMEPAD_BUTTON_X:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
        case PHYS_GAMEPAD_BUTTON_Y:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP);
        case PHYS_GAMEPAD_SHOULDER_LEFT_TRIGGER:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1);
        case PHYS_GAMEPAD_SHOULDER_LEFT_BUMPER:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_2);
        case PHYS_GAMEPAD_SHOULDER_RIGHT_TRIGGER:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
        case PHYS_GAMEPAD_SHOULDER_RIGHT_BUMPER:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_2);
        case PHYS_GAMEPAD_BUTTON_BACK:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_LEFT);
        case PHYS_GAMEPAD_BUTTON_START:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE_RIGHT);
        case PHYS_GAMEPAD_THUMB_LEFT_CLICK:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB);
        case PHYS_GAMEPAD_THUMB_RIGHT_CLICK:
            return IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_THUMB);
        default:
            return false;
    }
}