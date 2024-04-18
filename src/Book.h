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
  std::string author;
  std::string isbn;
  int year;
  std::string publisher;
  int pages;

public:
  Book(
      std::string title,
      std::string author,
      std::string isbn,
      int year,
      std::string publisher,
      int pages);

  void setTitle(std::string title);
  void setAuthor(std::string author);
  void setIsbn(std::string isbn);
  void setYear(int year);
  void setPublisher(std::string publisher);
  void setPages(int pages);

  std::string const getTitle();
  std::string const getAuthor();
  std::string const getIsbn();
  int const getYear();
  std::string const getPublisher();
  int const getPages();
};
