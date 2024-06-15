#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"
#include "Storage.h"
#include "Book.h"
#include "Library.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define Q 'q'

void previewBooks(Library &library);
void listBooks(Library &library);
void findBook(Library &library);
void addBook(Library &library);
void editBook(Library &library);
void editBookForm(Book *foundBook);
void removeBook(Library &library);
void removeBookForm(Library &library, Book *foundBook);

void previewUsers(Library &library);
void listUsers(Library &library);
void findUser(Library &library);
void addUser(Library &library);
void editUser(Library &library);
void editUserForm(User *foundUser);
void removeUser(Library &library);
void removeUserForm(Library &library, User *foundUser);

void saveToFile(Library &library, Storage &storage);
void loadFromFile(Library &library, Storage &storage);

/**
 * Main function
 *
 * @return int
 */
int main()
{
  Storage storage("./dbFile.dat");

  Library library;
  loadFromFile(library, storage);

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
    cout << "1. Dodaj książkę" << endl;
    cout << "2. Przeglądaj książki" << endl;
    cout << endl;
    cout << "3. Dodaj czytelnika" << endl;
    cout << "4. Przeglądaj czytelników" << endl;
    cout << endl;
    cout << "r. Zapis do pliku" << endl;
    cout << "w. Odczyt z pliku" << endl;
    cout << Q << ". Wyjście" << endl;

    std::cout << "Wybierz opcje: ";
    readOption(option);

    /**
     * Switch statement
     */
    switch (option)
    {
    case '1':
      addBook(library);
      break;
    case '2':
      previewBooks(library);
      break;
    case '3':
      addUser(library);
      break;
    case '4':
      previewUsers(library);
      break;
    case 'r':
      saveToFile(library, storage);
      break;
    case 'w':
      loadFromFile(library, storage);
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
 * Preview books
 *
 */
void previewBooks(Library &library)
{
  char option;
  do
  {
    clearScreen();
    cout << "1. Lista książek" << endl;
    cout << "2. Znajdź książkę" << endl;
    cout << "3. Dodaj książkę" << endl;
    cout << "4. Edytuj książkę" << endl;
    cout << "5. Usuń książkę" << endl;
    cout << "b. Powrót" << endl;

    std::cout << "Wybierz opcje: ";
    readOption(option);

    switch (option)
    {
    case '1':
      listBooks(library);
      break;
    case '2':
      findBook(library);
      break;
    case '3':
      addBook(library);
      break;
    case '4':
      editBook(library);
      break;
    case '5':
      removeBook(library);
      break;
    case 'b':
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
    pause();
  } while (option != 'b');
}
/**
 * List books
 *
 */
void listBooks(Library &library)
{
  char option;

  do
  {
    clearScreen();
    cout << "Lista książek" << endl;
    vector<Book> books = library.getBooks();
    for (int i = 0; i < books.size(); i++)
    {
      cout << i + 1 << ". " << books[i].getTitle() << " - " << books[i].getAuthor() << " (" << books[i].getYear() << ")" << endl;
    }
    cout << endl;
    cout << "Sortuj rosnaco po:" << endl;
    cout << "(t) tytule" << endl;
    cout << "(a) autorze" << endl;
    cout << "(r) roku wydania" << endl;
    cout << "(b) powrot" << endl;
    cout << endl;
    char option;
    std::cout << "Wybierz opcje: ";
    readOption(option);

    switch (option)
    {
    case 't':
      library.sortBooksByTitle();
      break;

    case 'a':
      library.sortBooksByAuthor();
      break;

    case 'r':
      library.sortBooksByYear();
      break;
    case 'b':
      option = 'b';
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
  } while (option != 'b');
}

/**
 * Find book in library
 *
 */
void findBook(Library &library)
{
  string title;
  cout << "Znajdź książkę" << endl;

  cout << "(t) tytuł" << endl;
  cout << "(y) rok wydania" << endl;

  char option;
  std::cout << "Wybierz opcje: ";
  readOption(option);

  vector<Book *> foundBooks;

  if (option == 't')
  {
    cout << "Podaj tytuł książki: ";
    fflush(stdin);
    getline(cin, title);
    foundBooks = library.findBooksByTitle(title);
  }
  else if (option == 'y')
  {
    int year;
    cout << "Podaj rok wydania książki: ";
    fflush(stdin);
    cin >> year;
    foundBooks = library.findBooksByYear(year);
  }

  if (foundBooks.size() == 0)
  {
    cout << "Nie znaleziono książki" << endl;
    return;
  }

  int index = 0;

  do
  {
    clearScreen();
    cout << "Znaleziono " << foundBooks.size() << " książek" << endl;
    Book *foundBook = foundBooks[index];

    cout << "#" << index + 1 << ". Znaleziona książka" << endl;
    cout << endl;
    cout << "Tytuł: " << foundBook->getTitle() << endl;
    cout << "Autor: " << foundBook->getAuthor() << endl;
    cout << "ISBN: " << foundBook->getIsbn() << endl;
    cout << "Rok wydania: " << foundBook->getYear() << endl;
    cout << "Wydawca: " << foundBook->getPublisher() << endl;
    cout << "Ilość stron: " << foundBook->getPages() << endl;
    cout << endl;

    cout << "(e) Edytuj książkę" << endl;
    cout << "(d) Usuń książkę" << endl;
    cout << endl;
    if (index < foundBooks.size() - 1)
    {
      cout << "(n) Następna książka" << endl;
    }
    if (index > 0)
    {
      cout << "(p) Poprzednia książka" << endl;
    }
    cout << endl;
    cout << "(b) Powrót" << endl;

    std::cout << "Wybierz opcje: ";
    readOption(option);

    switch (option)
    {
    case 'n':
      if (index < foundBooks.size() - 1)
      {
        index++;
      }
      break;
    case 'p':
      if (index > 0)
      {
        index--;
      }
      break;
    case 'b':
      break;
    case 'e':
      editBookForm(foundBook);
      break;
    case 'd':
      removeBookForm(library, foundBook);
      option = 'b';
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
  } while (option != 'b');
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
  do
  {
    cout << "Podaj tytuł książki: ";
    fflush(stdin);
    getline(cin, title);
    if (title.empty())
    {
      cout << "Nieprawidłowy tytuł" << endl;
    }
  } while (title.empty());

  do
  {
    cout << "Podaj autora książki: ";
    fflush(stdin);
    getline(cin, author);
    if (author.empty())
    {
      cout << "Nieprawidłowy autor" << endl;
    }
  } while (author.empty());

  do
  {
    cout << "Podaj ISBN książki: ";
    fflush(stdin);
    getline(cin, isbn);
    if (isbn.empty())
    {
      cout << "Nieprawidłowy ISBN" << endl;
    }
  } while (isbn.empty());

  do
  {
    cout << "Podaj rok wydania książki: ";
    fflush(stdin);
    cin >> year;
    if (year < 0 || year > 2024)
    {
      cout << "Nieprawidłowy rok" << endl;
    }
  } while (year < 0 || year > 2024);

  do
  {
    cout << "Podaj wydawcę książki: ";
    fflush(stdin);
    getline(cin, publisher);
    if (publisher.empty())
    {
      cout << "Nieprawidłowy wydawca" << endl;
    }
  } while (publisher.empty());

  do
  {
    cout << "Podaj ilość stron książki: ";
    fflush(stdin);
    cin >> pages;
    if (pages < 0)
    {
      cout << "Nieprawidłowa ilość stron" << endl;
    }
  } while (pages < 0);

  Book book(title, author, isbn, year, publisher, pages);
  library.addBook(book);

  cout << "Dodano książkę" << endl;
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

  editBookForm(foundBook);
}

/**
 * Edit book form in library
 *
 */
void editBookForm(Book *foundBook)
{
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

    std::cout << "Wybierz opcje: ";
    readOption(option);

    string newValueTekst = "";
    int newValueNumer = 0;

    switch (option)
    {
    case '1':
      do
      {
        cout << "Podaj nowy tytuł książki: ";
        fflush(stdin);
        getline(cin, newValueTekst);
        if (newValueTekst.empty())
        {
          cout << "Nieprawidłowy tytuł" << endl;
        }
      } while (newValueTekst.empty());
      foundBook->setTitle(newValueTekst);
      cout << "Zmieniono tytuł książki na: " << foundBook->getTitle() << endl;
      break;
    case '2':
      do
      {
        cout << "Podaj nowego autora książki: ";
        fflush(stdin);
        getline(cin, newValueTekst);
        if (newValueTekst.empty())
        {
          cout << "Nieprawidłowy autor" << endl;
        }
      } while (newValueTekst.empty());
      foundBook->setAuthor(newValueTekst);
      cout << "Zmieniono autora książki na: " << foundBook->getAuthor() << endl;
      break;
    case '3':
      do
      {
        cout << "Podaj nowy ISBN książki: ";
        fflush(stdin);
        getline(cin, newValueTekst);
        if (newValueTekst.empty())
        {
          cout << "Nieprawidłowy ISBN" << endl;
        }
      } while (newValueTekst.empty());
      foundBook->setIsbn(newValueTekst);
      cout << "Zmieniono ISBN książki na: " << foundBook->getIsbn() << endl;
      break;
    case '4':
      do
      {
        cout << "Podaj nowy rok wydania książki: ";
        fflush(stdin);
        cin >> newValueNumer;
        if (newValueNumer < 0 || newValueNumer > 2024)
        {
          cout << "Nieprawidłowy rok" << endl;
        }
      } while (newValueNumer < 0 || newValueNumer > 2024);
      foundBook->setYear(newValueNumer);
      cout << "Zmieniono rok wydania książki na: " << foundBook->getYear() << endl;
      break;
    case '5':
      do
      {
        cout << "Podaj nowego wydawcę książki: ";
        fflush(stdin);
        getline(cin, newValueTekst);
        if (newValueTekst.empty())
        {
          cout << "Nieprawidłowy wydawca" << endl;
        }
      } while (newValueTekst.empty());
      foundBook->setPublisher(newValueTekst);
      cout << "Zmieniono wydawcę książki na: " << foundBook->getPublisher() << endl;
      break;
    case '6':
      do
      {
        cout << "Podaj nową ilość stron książki: ";
        fflush(stdin);
        cin >> newValueNumer;
        if (newValueNumer < 0)
        {
          cout << "Nieprawidłowa ilość stron" << endl;
        }
      } while (newValueNumer < 0);
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
  removeBookForm(library, foundBook);
}

/**
 * Remove book form in library
 */
void removeBookForm(Library &library, Book *foundBook)
{
  cout << "Czy na pewno chcesz usunąć książkę? (t/n): ";
  char option;
  readOption(option);
  if (option != 't')
    return;

  library.removeBook(*foundBook);

  cout << "Usunięto książkę" << endl;
}

/**
 * Preview users
 *
 */
void previewUsers(Library &library)
{
  char option;
  do
  {
    clearScreen();
    cout << "1. Lista czytelników" << endl;
    cout << "2. Znajdź czytelnika" << endl;
    cout << "3. Dodaj czytelnika" << endl;
    cout << "4. Edytuj czytelnika" << endl;
    cout << "5. Usuń czytelnika" << endl;
    cout << "b. Powrót" << endl;

    readOption(option);

    switch (option)
    {
    case '1':
      listUsers(library);
      break;
    case '2':
      findUser(library);
      break;
    case '3':
      addUser(library);
      break;
    case '4':
      editUser(library);
      break;
    case '5':
      removeUser(library);
      break;
    case 'b':
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
    pause();
  } while (option != 'b');
}

/**
 * List users
 *
 */
void listUsers(Library &library)
{
  cout << "Lista czytelników" << endl;
  vector<User> users = library.getUsers();
  for (int i = 0; i < users.size(); i++)
  {
    cout << i + 1 << ". " << users[i].getName() << " - " << users[i].getEmail() << " (" << users[i].getPhoneNumber() << ")" << endl;
  }
}

/**
 * Find user in library
 *
 */
void findUser(Library &library)
{

  cout << "Znajdź czytelnika" << endl;

  cout << "(n) imie i nazwisko" << endl;
  cout << "(e) email" << endl;

  char option;
  std::cout << "Wybierz opcje: ";
  readOption(option);

  vector<User *> foundUsers;

  if (option == 'n')
  {
    string name;
    cout << "Podaj imie lub/i nazwisko: ";
    fflush(stdin);
    getline(cin, name);
    foundUsers = library.findUsersByName(name);
  }
  else if (option == 'e')
  {
    string email;
    cout << "Podaj email: ";
    fflush(stdin);
    getline(cin, email);
    foundUsers = library.findUsersByEmail(email);
  }

  if (foundUsers.size() == 0)
  {
    cout << "Nie znaleziono czytelnika" << endl;
    return;
  }

  int index = 0;

  do
  {
    clearScreen();
    cout << "Znaleziono " << foundUsers.size() << " czytelnikow" << endl;
    User *foundUser = foundUsers[index];

    cout << "#" << index + 1 << ". Znaleziony czytelnik" << endl;
    cout << endl;
    cout << "Imię i nazwisko: " << foundUser->getName() << endl;
    cout << "Email: " << foundUser->getEmail() << endl;
    cout << "Adres: " << foundUser->getAddress() << endl;
    cout << "Telefon: " << foundUser->getPhoneNumber() << endl;
    cout << endl;

    cout << "(e) Edytuj czytelnika" << endl;
    cout << "(d) Usuń czytelnika" << endl;
    cout << endl;
    if (index < foundUsers.size() - 1)
    {
      cout << "(n) Następny czytelnik" << endl;
    }
    if (index > 0)
    {
      cout << "(p) Poprzedni czytelnik" << endl;
    }
    cout << endl;
    cout << "(b) Powrót" << endl;

    readOption(option);

    switch (option)
    {
    case 'n':
      if (index < foundUsers.size() - 1)
      {
        index++;
      }
      break;
    case 'p':
      if (index > 0)
      {
        index--;
      }
      break;
    case 'b':
      break;
    case 'e':
      editUserForm(foundUser);
      break;
    case 'd':
      removeUserForm(library, foundUser);
      option = 'b';
      break;
    default:
      cout << "Nieprawidłowa opcja" << endl;
      break;
    }
  } while (option != 'b');
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
  do
  {
    cout << "Podaj imię i nazwisko czytelnika: ";
    fflush(stdin);
    getline(cin, name);
    if (name.empty())
    {
      cout << "Nieprawidłowe imię i nazwisko" << endl;
    }
  } while (name.empty());
  do
  {
    cout << "Podaj email czytelnika: ";
    fflush(stdin);
    getline(cin, email);
    if (email.empty())
    {
      cout << "Nieprawidłowy email" << endl;
    }
  } while (email.empty());
  do
  {
    cout << "Podaj adres czytelnika: ";
    fflush(stdin);
    getline(cin, address);
    if (address.empty())
    {
      cout << "Nieprawidłowy adres" << endl;
    }
  } while (address.empty());
  do
  {
    cout << "Podaj telefon czytelnika: ";
    fflush(stdin);
    getline(cin, phone);
    if (phone.empty())
    {
      cout << "Nieprawidłowy telefon" << endl;
    }
  } while (phone.empty());

  User user(name, email, address, phone);
  library.addUser(user);

  cout << "Dodano czytelnika" << endl;
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
    return;
  }

  cout << "Znaleziono czytelnika: " << foundUser->getName() << endl;

  editUserForm(foundUser);
}

/**
 * Edit user form in library
 *
 */
void editUserForm(User *foundUser)
{
  char option;
  do
  {
    cout << "Co chcesz edytować?" << endl;
    cout << "1. Imię i nazwisko" << endl;
    cout << "2. Email" << endl;
    cout << "3. Adres" << endl;
    cout << "4. Telefon" << endl;
    cout << "b. Powrót" << endl;

    readOption(option);

    string newValueTekst = "";
    int newValueNumber = 0;

    switch (option)
    {
    case '1':
      do
      {
        cout << "Podaj nowe imię i nazwisko czytelnika: ";
        fflush(stdin);
        getline(cin, newValueTekst);
      } while (newValueTekst.empty());
      foundUser->setName(newValueTekst);
      cout << "Zmieniono imię i nazwisko czytelnika na: " << foundUser->getName() << endl;
      break;
    case '2':
      do
      {
        cout << "Podaj nowy email czytelnika: ";
        fflush(stdin);
        getline(cin, newValueTekst);
      } while (newValueTekst.empty());
      foundUser->setEmail(newValueTekst);
      cout << "Zmieniono email czytelnika na: " << foundUser->getEmail() << endl;
      break;
    case '3':
      do
      {
        cout << "Podaj nowy adres czytelnika: ";
        fflush(stdin);
        getline(cin, newValueTekst);
      } while (newValueTekst.empty());
      foundUser->setAddress(newValueTekst);
      cout << "Zmieniono adres czytelnika na: " << foundUser->getAddress() << endl;
      break;
    case '4':
      do
      {
        cout << "Podaj nowy telefon czytelnika: ";
        fflush(stdin);
        getline(cin, newValueTekst);
      } while (newValueTekst.empty());
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
  removeUserForm(library, foundUser);
}

/**
 * Remove user form in library
 */
void removeUserForm(Library &library, User *foundUser)
{
  cout << "Czy na pewno chcesz usunąć czytelnika? (t/n): ";
  char option;
  readOption(option);
  if (option != 't')
    return;

  library.removeUser(*foundUser);
  cout << "Usunięto czytelnika" << endl;
}

/**
 * Save library to file
 */
void saveToFile(Library &library, Storage &storage)
{
  cout << "Zapisywanie do pliku" << endl;
  std::ofstream file("./dbFile.dat");
  if (!file.is_open())
  {
    cout << "Nie można otworzyć pliku" << endl;
    return;
  }

  library.serialize(file);
  file.close();
  cout << "Zapisano do pliku" << endl;
}

/**
 * Load library from file
 */
void loadFromFile(Library &library, Storage &storage)
{
  cout << "Odczytywanie z pliku" << endl;
  std::ifstream file("./dbFile.dat", std::ios::in);
  if (!file.is_open())
  {
    cout << "Nie można otworzyć pliku" << endl;
    return;
  }

  library.deserialize(file);

  // Always close the file when done
  file.close();

  cout << "Odczytano z pliku" << endl;
}