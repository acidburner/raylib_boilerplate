#include "timer.h"

double get_platform_time_now(void)
{
  // Raylib's GetTime() returns time in seconds as a double since InitWindow is called
  return GetTime();
}

double get_platform_time_delta(double start, double end)
{
  return end - start;
}