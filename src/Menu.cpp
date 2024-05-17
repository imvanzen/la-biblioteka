#include <string>

#include "Menu.h"

#define Q 0

/**
 * Constructor for MenuItem
 */
MenuItem::MenuItem(std::string name, void (*action)(std::string)) : name(name), action(action){};

std::string MenuItem::getName() const
{
  return this->name;
};

void MenuItem::getAction(std::string name) const
{
  this->action(name);
};

/**
 * Constructor for Menu
 */
Menu::Menu(std::string name) : name(name){};

bool Menu::inRange(int option)
{
  return option > 0 && this->items.size() <= option;
};

Menu &Menu::addItem(const MenuItem &item)
{
  this->items.push_back(item);

  return *this;
};

void Menu::list()
{
  for (int i = 0; i < this->items.size(); i++)
  {
    std::cout << i + 1 << ". " << this->items[i].getName() << std::endl;
  }
};

void Menu::invoke(int option)
{
  this->items[option - 1].getAction(this->items[option - 1].getName());
};

void Menu::run()
{
  int option;
  do
  {
    std::cout << this->name << std::endl;

    this->list();

    std::cout << "Press '" << Q << "' to quit" << std::endl;

    std::cout << "Selected option: ";

    std::cin >> option;
    std::cin.clear();             // Clear the error flags
    std::cin.ignore(10000, '\n'); // Ignore the newline character

    std::cout << "Selected option: " << option << std::endl;
    this->invoke(option);
  } while (option != Q);

  std::cout << "Goodbye!" << std::endl;
};