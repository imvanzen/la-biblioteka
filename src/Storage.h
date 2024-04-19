#pragma once

#include <string>

/**
 * Storage class
 *
 * @param std::string fileName
 *
 * @return void
 */
class Storage
{
private:
  std::string fileName;

public:
  Storage(const std::string &fileName);

  int writeData(const std::string &data);
  std::string readData();
};
