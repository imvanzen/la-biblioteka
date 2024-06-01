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
