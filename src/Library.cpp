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
    if (this->users[i].getName() == name)
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