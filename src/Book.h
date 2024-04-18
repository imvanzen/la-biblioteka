#pragma once

#include <iostream>
#include <string>

/**
 * Book class
 *
 * @param std::string title
 *
 * @return void
 */
class Book
{
private:
  std::string title;

public:
  Book(std::string title);

  void setTitle(std::string title);

  std::string getTitle();
};
