#pragma once

#include <vector>
#include "Book.h"

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

public:
  Library();
  void addBook(const Book &book);
  vector<Book> getBooks();
};
