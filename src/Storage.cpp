#include <iostream>
#include <fstream>
#include <string>

#include "Storage.h"

/**
 * Storage constructor
 *
 * @param std::string fileName
 *
 * @return void
 */
Storage::Storage(const std::string &fileName) : fileName(fileName){};

/**
 * Write data to file
 *
 * @param std::string data
 *
 * @return int
 */
int Storage::writeData(const std::string &data)
{
  std::ofstream file(fileName);
  if (!file.is_open())
    return 0;

  file << data;
  file.close();
  return 1;
}

/**
 * Read data from file
 *
 * @return std::string
 */
std::string Storage::readData()
{
  std::ifstream file(this->fileName);
  std::string data;
  if (!file.is_open())
    return "";

  std::getline(file, data);
  file.close();
  return data;
}
