#pragma once

#include <vector>
#include <fstream>
#include <string>
#include "Book.h"
#include "User.h"

using std::string;
using std::vector;

/**
 * Library class
 *
 * @return void
 */
class Library
{
private:
  vector<Book> books;
  vector<User> users;

public:
  Library();

  Book *findBook(const string &title);
  User *findUser(const string &name);

  vector<Book *> findBooksByTitle(const string &title);
  vector<User *> findUsersByName(const string &name);

  vector<Book *> findBooksByYear(const int &year);
  vector<User *> findUsersByEmail(const string &email);

  void addBook(const Book &book);
  void addUser(const User &user);

  vector<Book> getBooks();
  vector<User> getUsers();

  void removeBook(const Book &book);
  void removeUser(const User &user);

  void sortBooksByTitle();
  void sortBooksByYear();
  void sortBooksByAuthor();

  void serialize(std::ostream &os) const;
  void deserialize(std::istream &is);
};
