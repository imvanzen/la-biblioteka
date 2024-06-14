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

  void addBook(const Book &book);
  void addUser(const User &user);

  vector<Book> getBooks();
  vector<User> getUsers();

  void removeBook(const Book &book);
  void removeUser(const User &user);

  void serialize(std::ostream &os) const;
  void deserialize(std::istream &is);
};
