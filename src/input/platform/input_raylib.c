
#include <raylib.h>
#include "input/input.h"
#include "input_raylib_helpers.h"
#include "core/log/log.h"

static void rl_update(void)
{
    // In raylib, input is updated automatically in the main loop,
    // so this function can be left empty or used for custom input handling if needed.
}

static bool rl_is_key_pressed(PhysicalKeysInput key)
{
  return is_key_pressed(key);
}

static bool rl_is_key_down(PhysicalKeysInput key)
{
    return is_key_down(key);
}

const PlatformInputAPI RAYLIB_INPUT_API = {
    .update = rl_update,
    .key_pressed = rl_is_key_pressed,
    .key_down = rl_is_key_down
};

