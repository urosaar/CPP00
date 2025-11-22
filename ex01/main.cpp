#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream> 
     #include <ctype.h>
static bool is_empty_field(const std::string &s)
{
    return s.empty();
}

bool isDigitsOnly(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}
bool isAllphabets(const std::string &s)
{
    if (s.empty()) return false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if(s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z')
            return false;
    }
    return true;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break;
        if (command == "ADD" || command == "add")
        {
            Contact newContact;
            std::string input;

            while(true)
            {
                std::cout << "Enter First Name: ";
                if (!std::getline(std::cin, input))
                    break;
                if (is_empty_field(input)) 
                { 
                    std::cout << "Field cannot be empty. Contact not saved.try again\n";
                    continue;
                }
                if(!isAllphabets(input))
                {
                    std::cout << "Invalid first name. Must contain alphabets only. Try again.\n";
                    continue;
                }
                newContact.TheFirstName(input);
                PhoneBook::DuplicateField dup = phoneBook.checkDuplicateField(newContact);
                if(dup != PhoneBook::NONE)
                {
                    if (dup == PhoneBook::FIRST_NAME)
                    {
                        std::cout << "This First Name already exists.\n";
                        continue;
                    }
                }
                break;
            }
            while(true)
            {
                std::cout << "Enter Last Name: ";
                if (!std::getline(std::cin, input))
                    break;
                if (is_empty_field(input))
                {
                    std::cout << "Field cannot be empty. Contact not saved.try again \n";
                    continue;
                }
                if(!isAllphabets(input))
                {
                    std::cout << "Invalid last name. Must contain alphabets only. Try again.\n";
                    continue;
                }
                newContact.TheLastName(input);
                // PhoneBook::DuplicateField dup = phoneBook.checkDuplicateField(newContact);
                // if(dup != PhoneBook::NONE)
                // {
                //     if (dup == PhoneBook::LAST_NAME)
                //     {
                //         std::cout << "This Last Name already exists.\n";
                //         continue;
                //     }
                // }
                break;
            }
            while (true)
            {
                std::cout << "Enter Phone Number: ";
                if (!std::getline(std::cin, input))
                    break;
                if (is_empty_field(input))
                {
                    std::cout << "Field cannot be empty. Try again.\n";
                    continue;
                }
                if (!isDigitsOnly(input))
                {
                    std::cout << "Invalid phone number. Must contain digits only. Try again.\n";
                    continue;
                }
                newContact.ThePhoneNumber(input);
                PhoneBook::DuplicateField dup = phoneBook.checkDuplicateField(newContact);
                if(dup != PhoneBook::NONE)
                {
                 if (dup == PhoneBook::PHONE_NUMBER)
                {
                        std::cout << "This phone number already exists.\n";
                        continue;
                    }
                }
                break; 
            }
            while(true)
            {
                std::cout << "Enter Nickname: ";
                if (!std::getline(std::cin, input))
                    break;
                newContact.TheNickname(input);
                if (is_empty_field(input))
                { 
                    std::cout << "Field cannot be empty. Contact not saved.try again\n";
                    continue;
                }
                if(!isAllphabets(input))
                {
                    std::cout << "Invalid nickname. Must contain alphabets only. Try again.\n";
                    continue;
                }
                newContact.TheNickname(input);
                PhoneBook::DuplicateField dup = phoneBook.checkDuplicateField(newContact);
                if(dup != PhoneBook::NONE)
                {
                    if (dup == PhoneBook::NICKNAME)
                    {
                        std::cout << "This NickName already exists.\n";
                        continue;
                    }
                }
                break;
            }
            while(true)
            {
                std::cout << "Enter Darkest Secret: ";
                if (!std::getline(std::cin, input))
                    break;
                if (is_empty_field(input))
                {
                    std::cout << "Field cannot be empty. Contact not saved.try again\n";
                    continue;
                }
                newContact.TheDarkestSecret(input);
                phoneBook.addContact(newContact);
                break;
            }
        } 
        else if (command == "SEARCH" || command == "search")
        {
            if (phoneBook.gettotalContacts() == 0)
            {
                std::cout << "PhoneBook is empty.\n";
                continue;
            }
            phoneBook.seeContacts();
            std::string indexStr;
            int index;
            while (true)
            {
            std::cout << "Enter index of the contact to view details: ";
            if (!std::getline(std::cin, indexStr))
                break;
            std::stringstream ss(indexStr);
            if (!(ss >> index))
            {
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (index < 0 || index >= phoneBook.gettotalContacts())
            {
                std::cout << "Index out of range. Try again.\n";
                continue;
            }
            phoneBook.seeContactinfo(index);
            break;
            }
        }
        else if (command == "EXIT" || command == "exit")
            break;
        else 
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
