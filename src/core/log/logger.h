#include "log_api.h"

typedef struct Logger {
  LogApi api;
  void * impl;
} Logger;