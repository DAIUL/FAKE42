#include "PhoneBook.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	Contact::ClearContact()
{
	_first_name.clear();
	_last_name.clear();
	_nick_name.clear();
	_phone_number.clear();
	_darkest_secret.clear();
}

std::string	Contact::GetInfo(std::string str)
{
	if (str == "first_name")
		return (_first_name);
	if (str == "last_name")
		return (_last_name);
	if (str == "nick_name")
		return (_nick_name);
	if (str == "phone_number")
		return (_phone_number);
	if (str == "darkest_secret")
		return (_darkest_secret);
	return ("");
}

void	Contact::AddContact()
{
	while (this->_first_name.empty())
	{
		std::cout << "Enter first name -> ";
		std::getline(std::cin, this->_first_name);
	}
	while (this->_last_name.empty())
	{
		std::cout << "Enter last name -> ";
		std::getline(std::cin, this->_last_name);
	}
	while (this->_nick_name.empty())
	{
		std::cout << "Enter nickname -> ";
		std::getline(std::cin, this->_nick_name);
	}
	while (this->_phone_number.empty())
	{
		std::cout << "Enter phone number -> ";
		std::getline(std::cin, this->_phone_number);
	}
	while (this->_darkest_secret.empty())
	{
		std::cout << "Enter darkest secret -> ";
		std::getline(std::cin, this->_darkest_secret);
	}
}