#include <iostream>
#include "Library.h"

/**
 * Library class
 *
 * @return void
 */
Library::Library(){};

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
