cmake_minimum_required(VERSION 4.2)

project(
    raylib_boilerplate
    VERSION 0.1.0
    LANGUAGES C CXX
)

# --------------------
# C standard
# --------------------
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# --------------------
# Default build type
# --------------------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# --------------------
# Output directories
# --------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# --------------------
# Warnings
# --------------------
add_compile_options(-Wall -Wextra -Wpedantic)

# --------------------
# FetchContent
# --------------------
# include(FetchContent)

# --------------------
# raylib (FetchContent)
# --------------------
#locally built

# --------------------
# libtcod
# --------------------
# locally built

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

# FetchContent_MakeAvailable(raylib)

# --------------------
# Sources
# --------------------
file(GLOB_RECURSE GAME_SOURCES
    src/*.c
    src/*.h
)

add_executable(${PROJECT_NAME}
    ${GAME_SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        slog
)


# target_link_libraries(${PROJECT_NAME}
#     PRIVATE
#         tcod
# )

# --------------------
# Linux-specific libs
# --------------------
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            m
            pthread
            dl
    )
endif()

# --------------------
# Sanitizers (Debug)
# --------------------
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
endif()

# --------------------
# Assets copy
# --------------------
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets
)

add_dependencies(${PROJECT_NAME} copy_assets)
