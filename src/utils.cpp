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

/**
 * Pauza w programie do czasu naciśnięcia klawisza
 */
void pause()
{
  std::cout << "Naciśnij klawisz aby kontynuować..." << std::endl;
  std::cin.ignore();
  std::cin.get();
}
