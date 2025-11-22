#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
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