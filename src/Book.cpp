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
Book::Book(std::string title)
{
  this->title = title;
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
 * Get title
 *
 * @return std::string
 */
std::string Book::getTitle()
{
  return this->title;
};