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
std::string Book::getTitle() const
{
  return this->title;
};

/**
 * Get author
 *
 * @return std::string
 */
std::string Book::getAuthor() const
{
  return this->author;
};

/**
 * Get ISBN number
 *
 * @return std::string
 */
std::string Book::getIsbn() const
{
  return this->isbn;
};

/**
 * Get year of publication
 *
 * @return int
 */
int Book::getYear() const
{
  return this->year;
};

/**
 * Get publisher name
 *
 * @return std::string
 */
std::string Book::getPublisher() const
{
  return this->publisher;
};

/**
 * Get number of pages
 *
 * @return int
 */
int Book::getPages() const
{
  return this->pages;
};

/**
 * Serialize book
 *
 * @param std::ostream &os
 *
 * @return void
 */
void Book::serialize(std::ostream &os) const
{
  os << title << "\n"
     << author << "\n"
     << isbn << "\n"
     << year << "\n"
     << publisher << "\n"
     << pages << "\n";
}

/**
 * Deserialize book
 *
 * @param std::istream &is
 *
 * @return void
 */
void Book::deserialize(std::istream &is)
{
  std::getline(is, title);
  std::getline(is, author);
  std::getline(is, isbn);
  is >> year;
  is.ignore(); // Ignorujemy znak nowej linii po liczbie
  std::getline(is, publisher);
  is >> pages;
  is.ignore(); // Ignorujemy znak nowej linii po liczbie
}