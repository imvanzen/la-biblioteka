#include <iostream>
#include "Library.h"

/**
 * Library class
 *
 * @return void
 */
Library::Library(){};

/**
 * Find book in library
 *
 * @param Book book
 *
 * @return Book | nullptr
 */
Book *Library::findBook(const string &title)
{
  for (int i = 0; i < this->books.size(); i++)
  {
    if (this->books[i].getTitle().find(title) != string::npos)
    {
      return &this->books[i];
    }
  }

  return nullptr;
};

/**
 * Find books in library
 *
 * @param Book book
 *
 * @return vector<Book*>
 */
vector<Book *> Library::findBooks(const string &title)
{
  vector<Book *> books;
  for (int i = 0; i < this->books.size(); i++)
  {
    if (this->books[i].getTitle().find(title) != string::npos)
    {
      books.push_back(&this->books[i]);
    }
  }

  return books;
};

/**
 * Find users in library
 *
 * @param User user
 *
 * @return vector<User*>
 */
vector<User *> Library::findUsers(const string &name)
{
  vector<User *> users;
  for (int i = 0; i < this->users.size(); i++)
  {
    if (this->users[i].getName().find(name) != string::npos)
    {
      users.push_back(&this->users[i]);
    }
  }

  return users;
};

/**
 * Find user in library
 *
 * @param User user
 *
 * @return User | nullptr
 */
User *Library::findUser(const string &name)
{
  for (int i = 0; i < this->users.size(); i++)
  {
    if (this->users[i].getName().find(name) != string::npos)
    {
      return &this->users[i];
    }
  }

  return nullptr;
};

/**
 * Add book to library
 *
 * @param Book book
 *
 * @return void
 */

void Library::addBook(const Book &book)
{
  this->books.push_back(book);
};

/**
 * Add user to library
 *
 * @param User user
 *
 * @return void
 */

void Library::addUser(const User &user)
{
  this->users.push_back(user);
};

/**
 * Get all books from library
 *
 * @param Book book
 *
 * @return vector<Book>
 */

vector<Book> Library::getBooks()
{
  return this->books;
};

/**
 * Get all users from library
 *
 * @param User user
 *
 * @return vector<User>
 */

vector<User> Library::getUsers()
{
  return this->users;
};

/**
 * Remove book from library
 *
 * @param Book book
 *
 * @return void
 */

void Library::removeBook(const Book &book)
{
  for (int i = 0; i < this->books.size(); i++)
  {
    if (this->books[i].getTitle() == book.getTitle())
    {
      this->books.erase(this->books.begin() + i);
    }
  }
};

/**
 * Remove user from library
 *
 * @param User user
 *
 * @return void
 */

void Library::removeUser(const User &user)
{
  for (int i = 0; i < this->users.size(); i++)
  {
    if (this->users[i].getName() == user.getName())
    {
      this->users.erase(this->users.begin() + i);
    }
  }
};

/**
 * Serialize library
 *
 * @param ostream os
 *
 * @return void
 */

void Library::serialize(std::ostream &os) const
{
  os << this->books.size() << std::endl;
  for (int i = 0; i < this->books.size(); i++)
  {
    os << this->books[i].getTitle() << std::endl;
    os << this->books[i].getAuthor() << std::endl;
    os << this->books[i].getIsbn() << std::endl;
    os << this->books[i].getYear() << std::endl;
    os << this->books[i].getPublisher() << std::endl;
    os << this->books[i].getPages() << std::endl;
  }

  os << this->users.size() << std::endl;
  for (int i = 0; i < this->users.size(); i++)
  {
    os << this->users[i].getName() << std::endl;
    os << this->users[i].getEmail() << std::endl;
    os << this->users[i].getAddress() << std::endl;
    os << this->users[i].getPhoneNumber() << std::endl;
  }
};

/**
 * Deserialize library
 *
 * @param istream is
 *
 * @return void
 */

void Library::deserialize(std::istream &is)
{
  int booksSize;
  is >> booksSize;
  is.ignore();

  this->books = vector<Book>();
  for (int i = 0; i < booksSize; i++)
  {
    string title;
    string author;
    string isbn;
    int year;
    string publisher;
    int pages;

    std::getline(is, title);
    std::getline(is, author);
    std::getline(is, isbn);
    is >> year;
    is.ignore();
    std::getline(is, publisher);
    is >> pages;
    is.ignore();

    Book book(title, author, isbn, year, publisher, pages);
    this->books.push_back(book);
  }

  int usersSize;
  is >> usersSize;
  is.ignore();

  this->users = vector<User>();
  for (int i = 0; i < usersSize; i++)
  {
    string name;
    string email;
    string address;
    string phoneNumber;

    std::getline(is, name);
    std::getline(is, email);
    std::getline(is, address);
    std::getline(is, phoneNumber);

    User user(name, email, address, phoneNumber);
    this->users.push_back(user);
  }
};