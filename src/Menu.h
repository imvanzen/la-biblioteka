#include <iostream>
#include <string>
#include <vector>

/**
 * MenuItem class
 */
class MenuItem
{
private:
  std::string name;

  void (*action)(std::string) = nullptr;

public:
  MenuItem(std::string name, void (*action)(std::string));

  std::string getName() const;

  void getAction(std::string name) const;
};

/**
 * Menu class
 */
class Menu
{
private:
  int option;
  std::string name;
  std::vector<MenuItem> items;

  bool inRange(int option);

public:
  Menu(std::string name);

  Menu &addItem(const MenuItem &item);

  void list();

  void invoke();

  void run();
};