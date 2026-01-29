#pragma once
#include <stdint.h>

typedef enum LogLevel
{
  LOG_LEVEL_TRACE,
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_FATAL
} LogLevel;

// Bitmask for enabling levels in init()
typedef uint32_t LogLevelMask;

#define LOG_MASK_TRACE (1u << LOG_LEVEL_TRACE)
#define LOG_MASK_DEBUG (1u << LOG_LEVEL_DEBUG)
#define LOG_MASK_INFO (1u << LOG_LEVEL_INFO)
#define LOG_MASK_WARNING (1u << LOG_LEVEL_WARNING)
#define LOG_MASK_ERROR (1u << LOG_LEVEL_ERROR)
#define LOG_MASK_FATAL (1u << LOG_LEVEL_FATAL)
#define LOG_MASK_ALL (LOG_MASK_TRACE | LOG_MASK_DEBUG | LOG_MASK_INFO | LOG_MASK_WARNING | LOG_MASK_ERROR | LOG_MASK_FATAL)

// Helper if you want to convert a single LogLevel to a mask
#define LOG_LEVEL_TO_MASK(level) (1u << (level))

typedef struct LogApi
{
  void (*msg)(LogLevel level, const char *category, const char *format, ...);
  void (*init)(const char *log_file, LogLevelMask mask, uint8_t threadSafe);
  void (*shutdown)(void);
} LogApi;