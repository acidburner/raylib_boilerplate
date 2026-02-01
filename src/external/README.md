# External

FYI this folder is meant for external libraries that the project depends on, such as logging libraries, math libraries, etc. Libraries that aren't system specific, or developed in-house.

Examples: raylib, slog, libtcod. (currently these libraries are build system wide, so they are in their own folders under src/render/library, src/core/log/library, etc. But any additional external libraries that are added that aren't system specific can go here)

This directory contains third-party libraries and external dependencies used in the project. It includes source code, headers, and any necessary build scripts for integrating these libraries into the main application. Each library is organized in its own subdirectory for clarity and ease of maintenance.

These external libraries are generally pulled from their respective repositories and should not be modified directly.

When updating or adding new external libraries, ensure to follow the project's guidelines for versioning and compatibility. Document any changes made to the external dependencies in the project's main documentation to keep track of updates and modifications.

