#include <iostream>
#include <string>
#include "Storage.h"
#include "Book.h"
#include "Library.h"
#include "Menu.h"

using std::cin;
using std::cout;
using std::endl;

void blankAction(std::string name)
{
  cout << "Blank actio: " << name << endl;
}

/**
 * Main function
 *
 * @return int
 */
int main()
{
  // Storage storage("./dbFile.db");

  // cout << "Jakub Reczko - Programowanie obiektowe - Projekt Zaliczeniowy" << endl;

  // Book book1("Pan Tadeusz", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  // Book book2("Dziady", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  // Book book3("W pustyni i w puszczy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1911, "Czytelnik", 328);
  // Book book4("Krzyżacy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1900, "Czytelnik", 328);
  // Book book5("Ogniem i mieczem", "Henryk Sienkiewicz", "978-83-288-2376-0", 1884, "Czytelnik", 328);
  // Book book6("Quo Vadis", "Henryk Sienkiewicz", "978-83-288-2376-0", 1896, "Czytelnik", 328);

  // Library library;
  // library.addBook(book1);
  // library.addBook(book2);
  // library.addBook(book3);
  // library.addBook(book4);
  // library.addBook(book5);
  // library.addBook(book6);

  // cout << "Library books: " << library.getBooks().size() << endl;

  Menu menu = Menu("La Biblioteca - Menu Głowne");

  menu.addItem(MenuItem("Znajdź książkę", &blankAction));
  menu.addItem(MenuItem("Dodaj książkę", &blankAction));
  menu.addItem(MenuItem("Edytuj książkę", &blankAction));
  menu.addItem(MenuItem("Usuń książkę", &blankAction));

  menu.addItem(MenuItem("Znajdź czytelnika", &blankAction));
  menu.addItem(MenuItem("Dodaj czytelnika", &blankAction));
  menu.addItem(MenuItem("Edytuj czytelnika", &blankAction));
  menu.addItem(MenuItem("Usuń czytelnika", &blankAction));

  menu.addItem(MenuItem("Wypożycz książkę", &blankAction));
  menu.addItem(MenuItem("Oddaj książkę", &blankAction));

  menu.addItem(MenuItem("Wyświetl książki wypożyczone przez czytelnika", &blankAction));

  menu.run();

  return 0;
}