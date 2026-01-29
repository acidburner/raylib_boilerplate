#include "log_api.h"

/* Default category if none provided */
#ifndef LOG_CATEGORY
#define LOG_CATEGORY "General"
#endif

// Use LogApi* for the global logger
extern LogApi *global_logger;

// Frontend function that injects category
void log_msg(LogLevel level, const char *category, const char *fmt, ...);

// Category-injecting macros using the global logger
#define LOG_TRACE(fmt, ...) log_msg(LOG_LEVEL_TRACE, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) log_msg(LOG_LEVEL_DEBUG, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...) log_msg(LOG_LEVEL_INFO, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...) log_msg(LOG_LEVEL_WARNING, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) log_msg(LOG_LEVEL_ERROR, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_FATAL(fmt, ...) log_msg(LOG_LEVEL_FATAL, LOG_CATEGORY, fmt, ##__VA_ARGS__)

// Convenience macros to inject category with an explicit logger pointer
#define LOG_WITH(logger, level, fmt, ...) (logger)->msg(level, LOG_CATEGORY, fmt, ##__VA_ARGS__)
#define LOG_WITH_INFO(logger, fmt, ...) (logger)->msg(LOG_LEVEL_INFO, LOG_CATEGORY, fmt, ##__VA_ARGS__)