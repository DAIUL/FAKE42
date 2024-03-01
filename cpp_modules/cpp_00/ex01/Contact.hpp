#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include <cstdlib>

class Contact
{
private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:

	Contact();
	~Contact();

	void			AddContact();
	std::string		GetInfo(std::string str);
	void			ClearContact();
};

#endif