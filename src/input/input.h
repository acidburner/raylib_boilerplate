#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum InputKey
{
  INPUT_KEY_DEBUG_TOGGLE = 0,
  INPUT_KEY_MOVE_UP,
  INPUT_KEY_MOVE_DOWN,
  INPUT_KEY_MOVE_LEFT,
  INPUT_KEY_MOVE_RIGHT,
  INPUT_KEY_INTERACT,
  INPUT_KEY_PAUSE,
  // Add more keys as needed
  INPUT_KEY_COUNT // sentinel
} InputKey;

#define INPUT_KEY_MOVE_UP_BINDINGS { PHYS_KEYBOARD_KEY_W, PHYS_KEYBOARD_KEY_UP, PHYS_GAMEPAD_DPAD_UP, PHYS_KEY_NONE }
#define INPUT_KEY_MOVE_DOWN_BINDINGS { PHYS_KEYBOARD_KEY_S, PHYS_KEYBOARD_KEY_DOWN, PHYS_GAMEPAD_DPAD_DOWN, PHYS_KEY_NONE }
#define INPUT_KEY_MOVE_LEFT_BINDINGS { PHYS_KEYBOARD_KEY_A, PHYS_KEYBOARD_KEY_LEFT, PHYS_GAMEPAD_DPAD_LEFT, PHYS_KEY_NONE }
#define INPUT_KEY_MOVE_RIGHT_BINDINGS { PHYS_KEYBOARD_KEY_D, PHYS_KEYBOARD_KEY_RIGHT, PHYS_GAMEPAD_DPAD_RIGHT, PHYS_KEY_NONE }
#define INPUT_KEY_INTERACT_BINDINGS { PHYS_KEYBOARD_KEY_E, PHYS_KEYBOARD_KEY_ENTER, PHYS_GAMEPAD_BUTTON_A, PHYS_KEY_NONE }
#define INPUT_KEY_PAUSE_BINDINGS { PHYS_KEYBOARD_KEY_ESCAPE, PHYS_GAMEPAD_BUTTON_START, PHYS_KEY_NONE }
#define INPUT_KEY_DEBUG_TOGGLE_BINDINGS { PHYS_KEYBOARD_KEY_F1, PHYS_KEY_NONE }

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// physical keyboard keys
typedef enum PhysicalKeysInput
{
  PHYS_KEY_NONE = 0,

  // keyboard keys
  PHYS_KEYBOARD_KEY_W,
  PHYS_KEYBOARD_KEY_A,
  PHYS_KEYBOARD_KEY_S,
  PHYS_KEYBOARD_KEY_D,
  PHYS_KEYBOARD_KEY_UP,
  PHYS_KEYBOARD_KEY_DOWN,
  PHYS_KEYBOARD_KEY_LEFT,
  PHYS_KEYBOARD_KEY_RIGHT,
  PHYS_KEYBOARD_KEY_ESCAPE,
  PHYS_KEYBOARD_KEY_F1,
  PHYS_KEYBOARD_KEY_ENTER,
  PHYS_KEYBOARD_KEY_E,

  // mouse buttons
  PHYS_MOUSE_BUTTON_LEFT,
  PHYS_MOUSE_BUTTON_RIGHT,
  PHYS_MOUSE_BUTTON_MIDDLE,
  PHYS_MOUSE_BUTTON_SCROLL_UP,
  PHYS_MOUSE_BUTTON_SCROLL_DOWN,
  PHYS_MOUSE_BUTTON_FORWARD,
  PHYS_MOUSE_BUTTON_BACK,

  // gamepad buttons
  PHYS_GAMEPAD_DPAD_UP,
  PHYS_GAMEPAD_DPAD_DOWN,
  PHYS_GAMEPAD_DPAD_LEFT,
  PHYS_GAMEPAD_DPAD_RIGHT,
  PHYS_GAMEPAD_BUTTON_A,
  PHYS_GAMEPAD_BUTTON_B,
  PHYS_GAMEPAD_BUTTON_X,
  PHYS_GAMEPAD_BUTTON_Y,
  PHYS_GAMEPAD_SHOULDER_LEFT_TRIGGER,
  PHYS_GAMEPAD_SHOULDER_LEFT_BUMPER,
  PHYS_GAMEPAD_SHOULDER_RIGHT_TRIGGER,
  PHYS_GAMEPAD_SHOULDER_RIGHT_BUMPER,
  PHYS_GAMEPAD_BUTTON_BACK,
  PHYS_GAMEPAD_BUTTON_START,
  PHYS_GAMEPAD_THUMB_LEFT_CLICK,
  PHYS_GAMEPAD_THUMB_RIGHT_CLICK,

  // sentinel value
  PHYSICAL_KEY_COUNT
} PhysicalKeysInput;

// maximum number of physical keys per action
#define MAX_BINDINGS_PER_ACTION 4 //can be changed as needed

typedef enum InputDevice
{
  KEYBOARD,
  MOUSE,
  GAMEPAD,
} InputDevice;

// input mappings
typedef struct InputBinding
{
  InputDevice device;
  int code; // e.g., KeyboardInput, MouseInput, GamepadInput
} InputBinding;

typedef struct ActionBindings
{
  PhysicalKeysInput  bindings[MAX_BINDINGS_PER_ACTION];
  uint8_t count;
} ActionBindings;

typedef struct Input
{
  ActionBindings action_bindings[INPUT_KEY_COUNT]; // assuming a maximum of 32 actions
} Input;

typedef struct DefaultActionBinding
{
  PhysicalKeysInput keys[MAX_BINDINGS_PER_ACTION]; // sentinel-terminated
} DefaultActionBinding;

typedef struct PlatformInputAPI
{
  void (*update)(void);
  bool (*key_pressed)(PhysicalKeysInput key);
  bool (*key_down)(PhysicalKeysInput key);
} PlatformInputAPI;

typedef struct InputSystem
{
  Input bindings;
  PlatformInputAPI *platform;
} InputSystem;


void load_default_input_bindings(Input *bindings);
bool input_action_pressed(InputSystem *input, InputKey action);
bool input_action_down(InputSystem *input, InputKey action);