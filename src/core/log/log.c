#include "core/log/log.h"
#include "core/log/library/slog/log.h" // for SLOG_LOG_API fallback
#include <stdarg.h>
#include <stdio.h>

LogApi *global_logger = NULL;

void log_msg(LogLevel level, const char *category, const char *fmt, ...)
{
  char buffer[1024];

  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  // Use the configured backend if present, otherwise fallback to SLOG
  const LogApi *api = global_logger ? global_logger : &SLOG_LOG_API;
  api->msg(level, category, "%s", buffer);
}