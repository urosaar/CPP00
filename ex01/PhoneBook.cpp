#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>


static std::string truncate10(const std::string &s)
{
    if (s.length() <= 10)
        return s;
    return s.substr(0, 9) + ".";
}

PhoneBook::PhoneBook()
{
    next = 0;
    totalContacts = 0;
}
int PhoneBook::gettotalContacts()
{
    return totalContacts;
}
void PhoneBook::addContact(Contact c)
{
    contacts[next] = c;
    next = (next + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::seeContacts()
{
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "|         this is your phone book         |" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  std::cout << "|" << std::setw(10) << "Index" << "|"
  << std::setw(10) << "First Name" << "|"
  << std::setw(10) << "Last Name" << "|"
  << std::setw(10) << "Nickname" << "|" << std::endl;
  std::cout << "-------------------------------------------" << std::endl;
  
  for (int i = 0; i < totalContacts; i++) {
    std::string fn = truncate10(contacts[i].inputFirstName());
        std::string ln = truncate10(contacts[i].inputLastName());
        std::string nn = truncate10(contacts[i].inputNickname());
        
        std::cout << "|" << std::setw(10) << i << "|"
        << std::setw(10) << fn << "|"
        << std::setw(10) << ln << "|"
        << std::setw(10) << nn << "|" << std::endl;
      }
    std::cout << "-------------------------------------------" << std::endl;
}

void PhoneBook::seeContactinfo(int index)
{
  if (index < 0 || index >= totalContacts)
    {
      std::cout << "Invalid index." << std::endl;
      return;
    }
    std::cout << "First Name: " << contacts[index].inputFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].inputLastName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].inputPhoneNumber() << std::endl;
    std::cout << "Nickname: " << contacts[index].inputNickname() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].inputDarkestSecret() << std::endl;
 }


PhoneBook::DuplicateField PhoneBook::checkDuplicateField(Contact &c)
{
    for (int i = 0; i < totalContacts; i++)
    {
        if (contacts[i].inputFirstName() == c.inputFirstName())
          return FIRST_NAME;
        if (contacts[i].inputLastName()  == c.inputLastName())
          return LAST_NAME;
        if (contacts[i].inputNickname()  == c.inputNickname())
          return NICKNAME;
        if (contacts[i].inputPhoneNumber() == c.inputPhoneNumber())
          return PHONE_NUMBER;
    }
    return NONE;
}