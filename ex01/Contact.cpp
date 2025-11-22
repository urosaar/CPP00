#include "Contact.hpp"


Contact::Contact() {

  firstName = "";
  lastName = "";
  phoneNumber = "";
  nickname = "";
  darkestSecret = "";
}
void Contact::TheFirstName(std::string s)
{
  firstName = s;
}
void Contact::TheLastName(std::string s)
{
  lastName = s;
}
void Contact::ThePhoneNumber(std::string s)
{
  phoneNumber = s;
}
void Contact::TheNickname(std::string s)
{
  nickname = s;
}
void Contact::TheDarkestSecret(std::string s)
{
  darkestSecret = s;
}
std::string Contact::inputFirstName()
{
  return firstName;
}
std::string Contact::inputLastName()
{
  return lastName;
}
std::string Contact::inputPhoneNumber()
{
  return phoneNumber;
}
std::string Contact::inputNickname()
{
  return nickname;
}
std::string Contact::inputDarkestSecret()
{
  return darkestSecret;
}
