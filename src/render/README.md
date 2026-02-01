# Render

This module is responsible for all rendering operations within the project. It provides an abstraction layer over the underlying graphics library (currently raylib) to facilitate drawing graphics, managing textures, and handling rendering contexts.

Render_API is a wrapper header to allow arbitrary render swapping. This is in case raylib turns out to be ass, or I need something more powerful in the future like SDL, or Vulkan directly.