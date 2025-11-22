#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string nickname;
    std::string darkestSecret;

public:
    Contact();
    void TheFirstName(std::string s);
    void TheLastName(std::string s);
    void ThePhoneNumber(std::string s);
    void TheNickname(std::string s);
    void TheDarkestSecret(std::string s);

    std::string inputFirstName();
    std::string inputLastName();
    std::string inputPhoneNumber();
    std::string inputNickname();
    std::string inputDarkestSecret();
        
};

#endif