#pragma once

#include <iostream>

#include <string>
#include "User.h"

/**
 * User constructor
 *
 * @param std::string name
 * @param std::string email
 * @param std::string address
 * @param std::string phoneNumber
 *
 */
User::User(const std::string name, const std::string email, const std::string address, const std::string phoneNumber)
    : name(name), email(email), address(address), phoneNumber(phoneNumber) {}

/**
 * Get name
 *
 * @return std::string
 */
std::string User::getName() const
{
  return name;
}

/**
 * Get email
 *
 * @return std::string
 */
std::string User::getEmail() const
{
  return email;
}

/**
 * Get address
 *
 * @return std::string
 */
std::string User::getAddress() const
{
  return address;
}

/**
 * Get phone number
 *
 * @return std::string
 */
std::string User::getPhoneNumber() const
{
  return phoneNumber;
}

/**
 * Set name
 *
 * @param std::string newName
 *
 * @return void
 */
void User::setName(const std::string newName)
{
  this->name = newName;
}

/**
 * Set email
 *
 * @param std::string newEmail
 *
 * @return void
 */
void User::setEmail(const std::string newEmail)
{
  this->email = newEmail;
}

/**
 * Set address
 *
 * @param std::string newAddress
 *
 * @return void
 */
void User::setAddress(const std::string newAddress)
{
  this->address = newAddress;
}

/**
 * Set phone number
 *
 * @param std::string newPhoneNumber
 *
 * @return void
 */
void User::setPhoneNumber(const std::string newPhoneNumber)
{
  this->phoneNumber = newPhoneNumber;
};