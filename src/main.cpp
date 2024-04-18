#include <iostream>
#include <string>
#include "Book.h"
#include "Library.h"

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

  Book book1("Pan Tadeusz", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  Book book2("Dziady", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  Book book3("W pustyni i w puszczy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1911, "Czytelnik", 328);
  Book book4("Krzyżacy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1900, "Czytelnik", 328);
  Book book5("Ogniem i mieczem", "Henryk Sienkiewicz", "978-83-288-2376-0", 1884, "Czytelnik", 328);
  Book book6("Quo Vadis", "Henryk Sienkiewicz", "978-83-288-2376-0", 1896, "Czytelnik", 328);

  cout << "Book 1: " << book1.getTitle() << endl;
  cout << "Book 2: " << book2.getTitle() << endl;
  cout << "Book 3: " << book3.getTitle() << endl;
  cout << "Book 4: " << book4.getTitle() << endl;
  cout << "Book 5: " << book5.getTitle() << endl;
  cout << "Book 6: " << book6.getTitle() << endl;

  Library library;
  library.addBook(book1);
  library.addBook(book2);
  library.addBook(book3);
  library.addBook(book4);
  library.addBook(book5);
  library.addBook(book6);

  cout << "Library books: " << library.getBooks().size() << endl;

  return 0;
}