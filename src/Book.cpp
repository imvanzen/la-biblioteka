#include <iostream>
#include <string>
#include "Book.h"

/**
 * Book constructor
 *
 * @param std::string title
 *
 * @return void
 */
Book::Book(std::string title,
           std::string author,
           std::string isbn,
           int year,
           std::string publisher,
           int pages)
{
  this->title = title;
  this->author = author;
  this->isbn = isbn;
  this->year = year;
  this->publisher = publisher;
  this->pages = pages;
};

/**
 * Set title
 *
 * @param std::string title
 *
 * @return void
 */
void Book::setTitle(std::string title)
{
  this->title = title;
};

/**
 * Set author
 *
 * @param std::string author
 *
 * @return void
 */
void Book::setAuthor(std::string author)
{
  this->author = author;
};

/**
 * Set ISBN number
 *
 * @param std::string isbn
 *
 * @return void
 */
void Book::setIsbn(std::string isbn)
{
  this->isbn = isbn;
};

/**
 * Set year of publication
 *
 * @param int year
 *
 * @return void
 */
void Book::setYear(int year)
{
  this->year = year;
};

/**
 * Set publisher
 *
 * @param std::string publisher
 *
 * @return void
 */
void Book::setPublisher(std::string publisher)
{
  this->publisher = publisher;
};

/**
 * Set pages
 *
 * @param int pages
 *
 * @return void
 */
void Book::setPages(int pages)
{
  this->pages = pages;
};

/**
 * Get title
 *
 * @return std::string
 */
std::string const Book::getTitle()
{
  return this->title;
};

/**
 * Get author
 *
 * @return std::string
 */
std::string const Book::getAuthor()
{
  return this->author;
};

/**
 * Get ISBN number
 *
 * @return std::string
 */
std::string const Book::getIsbn()
{
  return this->isbn;
};

/**
 * Get year of publication
 *
 * @return int
 */
int const Book::getYear()
{
  return this->year;
};

/**
 * Get publisher name
 *
 * @return std::string
 */
std::string const Book::getPublisher()
{
  return this->publisher;
};

/**
 * Get number of pages
 *
 * @return int
 */
int const Book::getPages()
{
  return this->pages;
};