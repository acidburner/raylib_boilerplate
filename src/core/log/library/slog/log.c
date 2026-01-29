#include "core/log/log_api.h"
#include <slog.h>
#include <stdarg.h>
#include <stdio.h>

void msg(LogLevel level, const char *category, const char *format, ...) {
    char buffer[1024];

    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    char final[1200];
    snprintf(final, sizeof(final), "[%s] %s", category, buffer);
    switch(level){
        case LOG_LEVEL_TRACE:
            slog_trace("%s", final);
            break;
        case LOG_LEVEL_DEBUG:
            slog_debug("%s", final);
            break;
        case LOG_LEVEL_INFO:
            slog_info("%s", final);
            break;
        case LOG_LEVEL_WARNING:
            slog_warn("%s", final);
            break;
        case LOG_LEVEL_ERROR:
            slog_error("%s", final);
            break;
        case LOG_LEVEL_FATAL:
            slog_fatal("%s", final);
            break;
        default:
            slog_error("Unknown logging level, error: %s", buffer);
            break;
    }
}

void init(const char *log_file, LogLevelMask mask, uint8_t threadSafe){
    unsigned int slog_flags = 0; // type compatible with slog
    // map LogLevelMask to slog flags
    if (mask & LOG_MASK_TRACE)
        slog_flags |= SLOG_TRACE;
    if (mask & LOG_MASK_DEBUG)
        slog_flags |= SLOG_DEBUG;
    if (mask & LOG_MASK_INFO)
        slog_flags |= SLOG_INFO;
    if (mask & LOG_MASK_WARNING)
        slog_flags |= SLOG_WARN;
    if (mask & LOG_MASK_ERROR)
        slog_flags |= SLOG_ERROR;
    if (mask & LOG_MASK_FATAL)
        slog_flags |= SLOG_FATAL;

    slog_init(log_file, slog_flags, threadSafe);
}
void shutdown(void){
    slog_destroy();
}

const LogApi SLOG_LOG_API = {
    .msg = msg,
    .init = init,
    .shutdown = shutdown,
};