#include <iostream>
#include <string>
#include "utils.h"
#include "Storage.h"
#include "Book.h"
#include "Library.h"
#include "Menu.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define Q 'q'

void findBook(Library &library);
void addBook(Library &library);
void editBook(Library &library);
void removeBook(Library &library);

void findUser(Library &library);
void addUser(Library &library);
void editUser(Library &library);
void removeUser(Library &library);

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
    clearScreen();

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
    fflush(stdin);
    option = getchar();
    cin.clear();             // Clear the error flags
    cin.ignore(10000, '\n'); // Ignore the newline character

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
      removeBook(library);
      break;
    case '5':
      findUser(library);
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

/**
 * Find book in library
 *
 */
void findBook(Library &library)
{
  string title;
  cout << "Znajdź książkę" << endl;
  cout << "Podaj tytuł książki: ";
  fflush(stdin);
  getline(cin, title);
  Book *foundBook = library.findBook(title);
  if (foundBook == nullptr)
  {
    cout << "Nie znaleziono książki" << endl;
    return;
  }

  cout << "Znaleziono książkę: " << foundBook->getTitle() << endl;
  cout << "Autor: " << foundBook->getAuthor() << endl;
  cout << "ISBN: " << foundBook->getIsbn() << endl;
  cout << "Rok wydania: " << foundBook->getYear() << endl;
  cout << "Wydawca: " << foundBook->getPublisher() << endl;
  cout << "Ilość stron: " << foundBook->getPages() << endl;
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
  fflush(stdin);
  getline(cin, title);
  cout << "Podaj autora książki: ";
  fflush(stdin);
  getline(cin, author);
  cout << "Podaj ISBN książki: ";
  fflush(stdin);
  getline(cin, isbn);
  cout << "Podaj rok wydania książki: ";
  fflush(stdin);
  cin >> year;
  cout << "Podaj wydawcę książki: ";
  fflush(stdin);
  getline(cin, publisher);
  cout << "Podaj ilość stron książki: ";
  fflush(stdin);
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
  getline(cin, title);
  Book *foundBook = library.findBook(title);

  if (foundBook == nullptr)
  {
    cout << "Nie znaleziono książki" << endl;
    return;
  }

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
      fflush(stdin);
      getline(cin, newValueTekst);
      foundBook->setTitle(newValueTekst);
      cout << "Zmieniono tytuł książki na: " << foundBook->getTitle() << endl;
      break;
    case '2':
      cout << "Podaj nowego autora książki: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundBook->setAuthor(newValueTekst);
      cout << "Zmieniono autora książki na: " << foundBook->getAuthor() << endl;
      break;
    case '3':
      cout << "Podaj nowy ISBN książki: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundBook->setIsbn(newValueTekst);
      cout << "Zmieniono ISBN książki na: " << foundBook->getIsbn() << endl;
      break;
    case '4':
      cout << "Podaj nowy rok wydania książki: ";
      fflush(stdin);
      cin >> newValueNumer;
      foundBook->setYear(newValueNumer);
      cout << "Zmieniono rok wydania książki na: " << foundBook->getYear() << endl;
      break;
    case '5':
      cout << "Podaj nowego wydawcę książki: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundBook->setPublisher(newValueTekst);
      cout << "Zmieniono wydawcę książki na: " << foundBook->getPublisher() << endl;
      break;
    case '6':
      cout << "Podaj nową ilość stron książki: ";
      fflush(stdin);
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

/**
 * Remove book from library
 *
 */
void removeBook(Library &library)
{
  string title;
  cout << "Usuń książkę" << endl;
  cout << "Podaj tytuł książki: ";
  getline(cin, title);
  Book *foundBook = library.findBook(title);
  if (foundBook == nullptr)
  {
    cout << "Nie znaleziono książki" << endl;
    return;
  }
  cout << "Znaleziono książkę: " << foundBook->getTitle() << endl;
  cout << "Czy na pewno chcesz usunąć książkę? (t/n): ";
  char option;
  fflush(stdin);
  cin >> option;
  if (option != 't')
    return;
  library.removeBook(*foundBook);
  cout << "Usunięto książkę" << endl;
}

/**
 * Find user in library
 *
 */
void findUser(Library &library)
{
  string name;
  cout << "Znajdź czytelnika" << endl;
  cout << "Podaj imię i nazwisko czytelnika: ";
  fflush(stdin);
  getline(cin, name);
  User *foundUser = library.findUser(name);
  if (foundUser == nullptr)
  {
    cout << "Nie znaleziono czytelnika" << endl;
    return;
  }

  cout << "Znaleziono czytelnika: " << foundUser->getName() << endl;
  cout << "Email: " << foundUser->getEmail() << endl;
  cout << "Adres: " << foundUser->getAddress() << endl;
  cout << "Telefon: " << foundUser->getPhoneNumber() << endl;
}

/**
 * Add user to library
 */
void addUser(Library &library)
{
  string name;
  string email;
  string address;
  string phone;

  cout << "Dodaj czytelnika" << endl;
  cout << "Podaj imię i nazwisko czytelnika: ";
  fflush(stdin);
  getline(cin, name);
  cout << "Podaj email czytelnika: ";
  fflush(stdin);
  getline(cin, email);
  cout << "Podaj adres czytelnika: ";
  fflush(stdin);
  getline(cin, address);
  cout << "Podaj telefon czytelnika: ";
  fflush(stdin);
  getline(cin, phone);

  User user(name, email, address, phone);
  library.addUser(user);
}

/**
 * Edit user in library
 */
void editUser(Library &library)
{
  string name;
  cout << "Edytuj czytelnika" << endl;
  cout << "Podaj imię i nazwisko czytelnika: ";
  fflush(stdin);
  getline(cin, name);
  User *foundUser = library.findUser(name);

  if (foundUser == nullptr)
  {
    cout << "Nie znaleziono czytelnika" << endl;
    return
  };

  cout << "Znaleziono czytelnika: " << foundUser->getName() << endl;

  char option;

  do
  {
    cout << "Co chcesz edytować?" << endl;
    cout << "1. Imię i nazwisko" << endl;
    cout << "2. Email" << endl;
    cout << "3. Adres" << endl;
    cout << "4. Telefon" << endl;
    cout << "b. Powrót" << endl;

    cout << "Wybierz opcje: ";
    cin >> option;
    cin.clear();             // Clear the error flags
    cin.ignore(10000, '\n'); // Ignore the newline character

    string newValueTekst = "";
    int newValueNumber = 0;
    fflush(stdin);

    switch (option)
    {
    case '1':
      cout << "Podaj nowe imię i nazwisko czytelnika: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundUser->setName(newValueTekst);
      cout << "Zmieniono imię i nazwisko czytelnika na: " << foundUser->getName() << endl;
      break;
    case '2':
      cout << "Podaj nowy email czytelnika: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundUser->setEmail(newValueTekst);
      cout << "Zmieniono email czytelnika na: " << foundUser->getEmail() << endl;
      break;
    case '3':
      cout << "Podaj nowy adres czytelnika: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundUser->setAddress(newValueTekst);
      cout << "Zmieniono adres czytelnika na: " << foundUser->getAddress() << endl;
      break;
    case '4':
      cout << "Podaj nowy telefon czytelnika: ";
      fflush(stdin);
      getline(cin, newValueTekst);
      foundUser->setPhoneNumber(newValueTekst);
      cout << "Zmieniono telefon czytelnika na: " << foundUser->getPhoneNumber() << endl;
      break;
    case 'b':
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
  } while (option != 'b');
}

/**
 * Remove user from library
 */
void removeUser(Library &library)
{
  string name;
  cout << "Usuń czytelnika" << endl;
  cout << "Podaj imię i nazwisko czytelnika: ";
  fflush(stdin);
  getline(cin, name);
  User *foundUser = library.findUser(name);
  if (foundUser == nullptr)
  {
    cout << "Nie znaleziono czytelnika" << endl;
    return;
  }

  cout << "Znaleziono czytelnika: " << foundUser->getName() << endl;
  cout << "Czy na pewno chcesz usunąć czytelnika? (t/n): ";
  char option;
  fflush(stdin);
  cin >> option;
  if (option != 't')
    return;
  library.removeUser(*foundUser);
  cout << "Usunięto czytelnika" << endl;
}