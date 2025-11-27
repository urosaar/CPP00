#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>

#define RED    "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RESET  "\033[0m"

class PhoneBook{
private:
    Contact contacts[8];
    int next;
    int totalContacts;

public:
    PhoneBook();

    int gettotalContacts();
    void addContact(Contact c);
    void seeContacts();
    void seeContactinfo(int index);
    enum DuplicateField { NONE, FIRST_NAME, LAST_NAME, NICKNAME, PHONE_NUMBER};
    DuplicateField checkDuplicateField(Contact &c);
};

#endif