#include <iostream>
#include <string>
#include "Book.h"

using std::cin;
using std::cout;
using std::endl;

/**
 * Main function
 *
 * @return int
 */
int main()
{
  cout << "Jakub Reczko - Programowanie obiektowe - Projekt Zaliczeniowy" << endl;

  Book book("Pan Tadeusz");

  cout << "Book title: " << book.getTitle() << endl;

  book.setTitle("Dziady");

  cout << "Book title: " << book.getTitle() << endl;

  return 0;
}