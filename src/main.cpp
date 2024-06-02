#include <iostream>
#include <string>
#include "utils.h"
#include "Storage.h"
#include "Book.h"
#include "Library.h"
#include "Views.h"
#include "Menu.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define Q 'q'

/**
 * Main function
 *
 * @return int
 */
int main()
{
  Storage storage("./dbFile.dat");

  cout << "Jakub Reczko - Programowanie obiektowe - Projekt Zaliczeniowy" << endl;

  Book book1("Pan Tadeusz", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  Book book2("Dziady", "Adam Mickiewicz", "978-83-288-2376-0", 1834, "Czytelnik", 328);
  Book book3("W pustyni i w puszczy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1911, "Czytelnik", 328);
  Book book4("Krzyżacy", "Henryk Sienkiewicz", "978-83-288-2376-0", 1900, "Czytelnik", 328);
  Book book5("Ogniem i mieczem", "Henryk Sienkiewicz", "978-83-288-2376-0", 1884, "Czytelnik", 328);
  Book book6("Quo Vadis", "Henryk Sienkiewicz", "978-83-288-2376-0", 1896, "Czytelnik", 328);

  User user1("Jan Kowalski", "jan.kowalski@mail.com", "ul. Kowalska 1", "123456789");
  User user2("Anna Nowak", "anna.kowalska@mail.com", "ul. Nowak 1", "987654321");
  User user3("Piot Kowalski", "piotr.kowalski@mail.com", "ul. Kowalska 2", "123456789");
  User user4("Kasia Nowak", "kasia.nowak@mail.com", "ul. Nowak 2", "987654321");

  Library library;

  library.addBook(book1);
  library.addBook(book2);
  library.addBook(book3);
  library.addBook(book4);
  library.addBook(book5);
  library.addBook(book6);

  library.addUser(user1);
  library.addUser(user2);
  library.addUser(user3);
  library.addUser(user4);

  cout << "Library books: " << library.getBooks().size() << endl;

  for (int i = 0; i < library.getBooks().size(); i++)
  {
    cout << library.getBooks()[i].getTitle() << endl;
  }

  cout << "Library users: " << library.getUsers().size() << endl;

  for (int i = 0; i < library.getUsers().size(); i++)
  {
    cout << library.getUsers()[i].getName() << endl;
  }

  storage.writeData("Hello World");
  std::string r = storage.readData();

  cout << r << endl;

  cout << "La Biblioteca - Menu Głowne" << endl;

  char option;
  do
  {
    option = -1;

    cout << "1. Znajdź książkę" << endl;
    cout << "2. Dodaj książkę" << endl;
    cout << "3. Edytuj książkę" << endl;
    cout << "4. Usuń książkę" << endl;
    cout << endl;
    cout << "5. Znajdź czytelnika" << endl;
    cout << "6. Dodaj czytelnika" << endl;
    cout << "7. Edytuj czytelnika" << endl;
    cout << "8. Usuń czytelnika" << endl;
    cout << endl;
    // cout << "9. Wypożycz książkę" << endl;
    // cout << "10. Oddaj książkę" << endl;

    cout << Q << ". Wyjście" << endl;

    cout << "Wybierz opcje: ";

    cin >> option;
    cin.clear();             // Clear the error flags
    cin.ignore(10000, '\n'); // Ignore the newline character

    cout << "Selected option: " << option << endl;

  } while (option != Q);

  cout << "Do widzenia!" << endl;

  return 0;
}