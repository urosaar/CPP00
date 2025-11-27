#include "PhoneBook.hpp"

static bool readLine(const std::string &prompt, std::string &out)
{
    std::cout << prompt;
    if (!std::getline(std::cin, out))
        return false;
    return true;
}

static bool isDigitsOnly(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); ++i)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

static bool isAllalphabets(const std::string &s)
{
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.length(); ++i)
        if (!std::isalpha(static_cast<unsigned char>(s[i])))
            return false;
    return true;
}

static bool promptFirstName(PhoneBook &pb, Contact &c)
{
    std::string input;
    while (true)
    {
        if (!readLine("Enter First Name: ", input))
            return false;
        if (input.empty())
        {
            std::cout << "Field cannot be empty. Try again.\n";
            continue;
        }
        if (!isAllalphabets(input))
        {
            std::cout << "Invalid first name. Alphabets only.\n";
            continue;
        }
        c.TheFirstName(input);
        PhoneBook::DuplicateField dup = pb.checkDuplicateField(c);
        if (dup == PhoneBook::FIRST_NAME)
        {
            std::cout << "This First Name already exists. Try again.\n";
            continue;
        }
        return true;
    }
}

static bool promptLastName(PhoneBook &pb, Contact &c)
{
    std::string input;
    while (true)
    {
        if (!readLine("Enter Last Name: ", input))
            return false;
        if (input.empty())
        {
            std::cout << "Field cannot be empty. Try again.\n";
            continue;
        }
        if (!isAllalphabets(input))
        {
            std::cout << "Invalid last name. Alphabets only.\n";
            continue;
        }
        c.TheLastName(input);
        PhoneBook::DuplicateField dup = pb.checkDuplicateField(c);
        if (dup == PhoneBook::LAST_NAME)
        {
            std::cout << "This Last Name already exists. Try again.\n";
            continue;
        }
        return true;
    }
}

static bool promptPhoneNumber(PhoneBook &pb, Contact &c)
{
    std::string input;
    while (true)
    {
        if (!readLine("Enter Phone Number: ", input))
            return false;
        if (input.empty())
        {
            std::cout << "Field cannot be empty. Try again.\n";
            continue;
        }
        if (!isDigitsOnly(input))
        { 
            std::cout << "Invalid phone number. Digits only.\n";
            continue;
        }
        c.ThePhoneNumber(input);
        PhoneBook::DuplicateField dup = pb.checkDuplicateField(c);
        if (dup == PhoneBook::PHONE_NUMBER)
        {
            std::cout << "This phone number already exists. Try again.\n";
            continue;
        }
        return true;
    }
}

static bool promptNickname(PhoneBook &pb, Contact &c)
{
    std::string input;
    while (true)
    {
        if (!readLine("Enter Nickname: ", input))
            return false;
        if (input.empty())
        { 
            std::cout << "Field cannot be empty. Try again.\n"; 
            continue;
        }
        if (!isAllalphabets(input))
        { 
            std::cout << "Invalid nickname. Alphabets only.\n";
            continue;
        }

        c.TheNickname(input);
        PhoneBook::DuplicateField dup = pb.checkDuplicateField(c);
        if (dup == PhoneBook::NICKNAME)
        { 
            std::cout << "This Nickname already exists. Try again.\n";
            continue;
        }
        return true;
    }
}

static bool promptDarkestSecret(Contact &c)
{
    std::string input;
    while (true)
    {
        if (!readLine("Enter Darkest Secret: ", input))
            return false;
        if (input.empty())
        { 
            std::cout << "Field cannot be empty. Try again.\n";
            continue;
        }
        c.TheDarkestSecret(input);
        return true;
    }
}

static bool handleAdd(PhoneBook &pb)
{
    Contact newContact;

    if (!promptFirstName(pb, newContact))
        return false;
    if (!promptLastName(pb, newContact))
        return false;
    if (!promptPhoneNumber(pb, newContact))
        return false;
    if (!promptNickname(pb, newContact))
        return false;
    if (!promptDarkestSecret(newContact))
        return false;
    pb.addContact(newContact);
    std::cout << "Contact added successfully.\n";
    return true;
}

static bool handleSearch(PhoneBook &pb)
{
    if (pb.gettotalContacts() == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return true;
    }

    pb.seeContacts();

    std::string indexStr;
    int index;
    while (true)
    {
        if (!readLine("Enter index of the contact to view details: ", indexStr))
            return false;
        std::stringstream ss(indexStr);
        if (!(ss >> index))
        { 
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (index < 0 || index >= pb.gettotalContacts())
        { 
            std::cout << "Index out of range. Try again.\n";
            continue;
        }
        pb.seeContactinfo(index);
        return true;
    }
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        if (!readLine("Enter a command (ADD, SEARCH, EXIT): ", command))
            break;
        if (command == "ADD" || command == "add")
        {
            if (!handleAdd(phoneBook))
            break;
        }
        else if (command == "SEARCH" || command == "search")
        {
            if (!handleSearch(phoneBook))
            break;
        }
        else if (command == "EXIT" || command == "exit")
            break;
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return 0;
}
