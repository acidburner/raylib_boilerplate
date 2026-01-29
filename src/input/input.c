#include "input.h"
#include "core/log/log.h"
#include "core/panic.h"
#include <stdlib.h>

const extern PlatformInputAPI RAYLIB_INPUT_API;

static const DefaultActionBinding INPUT_BINDING_DEFAULT[INPUT_KEY_COUNT] = {
    [INPUT_KEY_MOVE_UP] = {.keys = INPUT_KEY_MOVE_UP_BINDINGS},
    [INPUT_KEY_MOVE_DOWN] = {.keys = INPUT_KEY_MOVE_DOWN_BINDINGS},
    [INPUT_KEY_MOVE_LEFT] = {.keys = INPUT_KEY_MOVE_LEFT_BINDINGS},
    [INPUT_KEY_MOVE_RIGHT] = {.keys = INPUT_KEY_MOVE_RIGHT_BINDINGS},
    [INPUT_KEY_INTERACT] = {.keys = INPUT_KEY_INTERACT_BINDINGS},
    [INPUT_KEY_PAUSE] = {.keys = INPUT_KEY_PAUSE_BINDINGS},
    [INPUT_KEY_DEBUG_TOGGLE] = {.keys = INPUT_KEY_DEBUG_TOGGLE_BINDINGS},
};

void load_default_input_bindings(Input *bindings)
{
  if (!bindings)
  {
    PANIC("load_default_input_bindings: bindings are NULL");
    return;
  }
  for (int action = 0; action < INPUT_KEY_COUNT; ++action)
  {
    for (int index = 0; index < MAX_BINDINGS_PER_ACTION; ++index)
    {
      PhysicalKeysInput key = INPUT_BINDING_DEFAULT[action].keys[index];
      if (key == PHYS_KEY_NONE)
      {
        break;
      }
      ActionBindings *actionBindings = &bindings->action_bindings[action];
      actionBindings->bindings[actionBindings->count++] = key;
    }
  }
}

bool input_action_pressed(InputSystem *input, InputKey action)
{
  ActionBindings *binding = &input->bindings.action_bindings[action];
  for (int i = 0; i < binding->count; i++)
  {
    PhysicalKeysInput key = binding->bindings[i];
    if (input->platform->key_pressed(key))
    {
      return true;
    }
  }
  return false;
}
bool input_action_down(InputSystem *input, InputKey action)
{
  ActionBindings *binding = &input->bindings.action_bindings[action];
  for (int i = 0; i < binding->count; i++)
  {
    PhysicalKeysInput key = binding->bindings[i];
    if (input->platform->key_down(key))
    {
      return true;
    }
  }
  return false;
}