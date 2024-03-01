# include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::SetContact()
{
	if (_index >= 8)
	{
		std::cout << "Contact list is full !" << std::endl;
		std::cout << "This new contact will replace the oldest one" << std::endl;
		_contacts[_index % 8].ClearContact();
		_contacts[_index % 8].AddContact();
		_index++;
		std::cout << "Contact added !" << std::endl;
	}
	else
	{
		_contacts[_index % 8].AddContact();
		_index++;
		std::cout << "Contact added !" << std::endl;
	}
}

// void	PhoneBook::DisplayContact()
// {
// 	std::string entry;

// 	std::cout << "Enter the index of the contact that you want to see -> ";
// 	std::getline(std::cin, entry);
// 	if (_contacts[entry].GetInfo("first_name").empty())
// 	{

// 	}
// }

void	PhoneBook::DisplayPhoneBook()
{
	std::string	fname;
	std::string	lname;
	std::string	nname;
	std::string	phnb;
	std::string	dsecret;

	for (int j = 0; j < 8 && !_contacts[j].GetInfo("first_name").empty(); j++)
	{
		fname = _contacts[j].GetInfo("first_name");
		lname = _contacts[j].GetInfo("last_name");
		nname = _contacts[j].GetInfo("nick_name");
		phnb = _contacts[j].GetInfo("phone_number");
		dsecret = _contacts[j].GetInfo("darkest_secret");

		std::cout << std::setw(10) << j + 1;
		if (fname.size() > 10)
		{
			fname.resize(9);
			fname.append(".");
		}
		std::cout << "|" << std::setw(10) << fname;
		if (lname.size() > 10)
		{
			lname.resize(9);
			lname.append(".");
		}
		std::cout << "|" << std::setw(10) << lname;
		if (nname.size() > 10)
		{
			nname.resize(9);
			nname.append(".");
		}
		std::cout << "|" << std::setw(10) << nname;
		std::cout << "|" << std::setw(10) << nname << std::endl;
	}
}