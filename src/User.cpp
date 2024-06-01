#pragma once

#include <iostream>

#include <string>
#include "User.h"

User::User(const std::string &name, const std::string &email, const std::string &address, const std::string &phoneNumber)
    : name(name), email(email), address(address), phoneNumber(phoneNumber) {}

// Getters
std::string User::getName() const
{
  return name;
}

std::string User::getEmail() const
{
  return email;
}

std::string User::getAddress() const
{
  return address;
}

std::string User::getPhoneNumber() const
{
  return phoneNumber;
}

// Setters
void User::setName(const std::string &newName)
{
  name = newName;
}

void User::setEmail(const std::string &newEmail)
{
  email = newEmail;
}

void User::setAddress(const std::string &newAddress)
{
  address = newAddress;
}

void User::setPhoneNumber(const std::string &newPhoneNumber)
{
  phoneNumber = newPhoneNumber;
};