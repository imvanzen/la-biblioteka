#pragma once

#include <vector>
#include "Book.h"
#include "User.h"

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

  void addBook(const Book &book);
  void addUser(const User &user);

  vector<Book> getBooks();
  vector<User> getUsers();
};
