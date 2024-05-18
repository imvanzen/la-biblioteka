#include <iostream>
#include "utils.h"

using std::cin;
using std::cout;
using std::endl;

/**
 * Blank action
 *
 * @param std::string name
 * @return void
 */
void blankAction(std::string name)
{
  cout << "Blank action: " << name << endl;
}

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