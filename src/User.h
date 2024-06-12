#pragma once

#include <string>

class User
{
private:
  std::string name;
  std::string email;
  std::string address;
  std::string phoneNumber;

public:
  // Constructor
  User(const std::string name, const std::string email, const std::string address, const std::string phoneNumber);

  void serialize(std::ostream &os) const;
  void deserialize(std::istream &is);

  // Getters
  std::string getName() const;
  std::string getEmail() const;
  std::string getAddress() const;
  std::string getPhoneNumber() const;

  // Setters
  void setName(const std::string newName);
  void setEmail(const std::string newEmail);
  void setAddress(const std::string newAddress);
  void setPhoneNumber(const std::string newPhoneNumber);
};