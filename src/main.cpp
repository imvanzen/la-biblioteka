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
 * Find book in library
 *
 */
void findBook(Library &library)
{
  string title;
  cout << "Znajdź książkę" << endl;
  cout << "Podaj tytuł książki: ";
  cin >> title;
  Book *foundBook = library.findBook(title);
  if (foundBook != nullptr)
  {
    cout << "Znaleziono książkę: " << foundBook->getTitle() << endl;
  }
  else
  {
    cout << "Nie znaleziono książki" << endl;
  }
}

/**
 * Add book to library
 *
 */
void addBook(Library &library)
{
  string title;
  string author;
  string isbn;
  int year;
  string publisher;
  int pages;

  cout << "Dodaj książkę" << endl;
  cout << "Podaj tytuł książki: ";
  cin >> title;
  cout << "Podaj autora książki: ";
  cin >> author;
  cout << "Podaj ISBN książki: ";
  cin >> isbn;
  cout << "Podaj rok wydania książki: ";
  cin >> year;
  cout << "Podaj wydawcę książki: ";
  cin >> publisher;
  cout << "Podaj ilość stron książki: ";
  cin >> pages;

  Book book(title, author, isbn, year, publisher, pages);
  library.addBook(book);
}

/**
 * Edit book in library
 *
 */
void editBook(Library &library)
{
  string title;
  cout << "Edytuj książkę" << endl;
  cout << "Podaj tytuł książki: ";
  cin >> title;
  Book *foundBook = library.findBook(title);

  if (foundBook != nullptr)
  {
    cout << "Znaleziono książkę: " << foundBook->getTitle() << endl;

    char option;

    do
    {
      cout << "Co chcesz edytować?" << endl;
      cout << "1. Tytuł" << endl;
      cout << "2. Autor" << endl;
      cout << "3. ISBN" << endl;
      cout << "4. Rok wydania" << endl;
      cout << "5. Wydawca" << endl;
      cout << "6. Ilość stron" << endl;
      cout << "b. Powrót" << endl;

      cout << "Wybierz opcje: ";
      cin >> option;
      cin.clear();             // Clear the error flags
      cin.ignore(10000, '\n'); // Ignore the newline character

      string newValueTekst = "";
      int newValueNumer = 0;
      fflush(stdin);

      switch (option)
      {
      case '1':
        cout << "Podaj nowy tytuł książki: ";
        getline(cin, newValueTekst);
        foundBook->setTitle(newValueTekst);
        cout << "Zmieniono tytuł książki na: " << foundBook->getTitle() << endl;
        break;
      case '2':
        cout << "Podaj nowego autora książki: ";
        getline(cin, newValueTekst);
        foundBook->setAuthor(newValueTekst);
        cout << "Zmieniono autora książki na: " << foundBook->getAuthor() << endl;
        break;
      case '3':
        cout << "Podaj nowy ISBN książki: ";
        getline(cin, newValueTekst);
        foundBook->setIsbn(newValueTekst);
        cout << "Zmieniono ISBN książki na: " << foundBook->getIsbn() << endl;
        break;
      case '4':
        cout << "Podaj nowy rok wydania książki: ";
        cin >> newValueNumer;
        foundBook->setYear(newValueNumer);
        cout << "Zmieniono rok wydania książki na: " << foundBook->getYear() << endl;
        break;
      case '5':
        cout << "Podaj nowego wydawcę książki: ";
        getline(cin, newValueTekst);
        foundBook->setPublisher(newValueTekst);
        cout << "Zmieniono wydawcę książki na: " << foundBook->getPublisher() << endl;
        break;
      case '6':
        cout << "Podaj nową ilość stron książki: ";
        cin >> newValueNumer;
        foundBook->setPages(newValueNumer);
        cout << "Zmieniono ilość stron książki na: " << foundBook->getPages() << endl;
        break;
      case 'b':
        break;
      default:
        cout << "Nieprawidłowa opcja" << endl;
        break;
      }

    } while (option != 'b');
  }
  else
  {
    cout << "Nie znaleziono książki" << endl;
  }
}

/**
 * Main function
 *
 * @return int
 */
int main()
{
  Storage storage("./dbFile.dat");

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

  clearScreen();

  cout << "Jakub Reczko - Programowanie obiektowe - Projekt Zaliczeniowy" << endl;
  cout << "La Biblioteca - Menu Głowne" << endl;

  char option;
  do
  {
    /**
     * Menu
     */
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
    cout << "r. Zapis do pliku" << endl;
    cout << "w. Odczyt z pliku" << endl;
    cout << Q << ". Wyjście" << endl;

    /**
     * Get the option
     */
    cout << "Wybierz opcje: ";
    option = getchar();

    /**
     * Switch statement
     */
    switch (option)
    {
    case '1':
      findBook(library);
      break;
    case '2':
      addBook(library);
      break;
    case '3':
      editBook(library);
      break;
    case '4':

      break;
    case '5':

      break;
    case '6':

      break;
    case '7':

      break;
    case '8':

      break;
    case 'r':

      break;
    case 'w':

      break;
    case Q:
      break;
    }

    pause();

  } while (option != Q);

  cout << "Do widzenia!" << endl;

  return 0;
}