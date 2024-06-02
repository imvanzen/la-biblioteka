#include <iostream>
#include "utils.h"

/**
 * Clear screen
 *
 * @return void
 */
void clearScreen()
{
// Clear screen based on the operating system
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}