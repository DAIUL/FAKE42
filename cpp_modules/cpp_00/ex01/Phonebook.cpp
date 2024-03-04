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

void	PhoneBook::DisplayContact()
{
	std::string entry;

	while (1)
	{
		if (_contacts[0].GetInfo("first_name").empty())
		{
			std::cout << "Set up some contacts before !" << std::endl;
			return ;
		}
		std::cout << "Enter the index of the contact that you want to see -> ";
		std::getline(std::cin, entry);
		if (entry.size() > 1)
			std::cout << "Enter a number between 0 and 9" << std::endl;
		else if ((int)(entry[0] - 48) > 8 || (int)(entry[0] - 48) < 1)
			std::cout << "Enter a number between 0 and 9" << std::endl;
		else if (_contacts[(int)((entry[0] - 48) - 1)].GetInfo("first_name").empty())
		{
			std::cout << (int)(entry[0] - 48) << std::endl;
			std::cout << "This contact has not been setted up yet" << std::endl;
		}
		else
		{
			std::cout << "First name : " << _contacts[(int)((entry[0] - 48) - 1)].GetInfo("first_name") << std::endl;
			std::cout << "Last name : " << _contacts[(int)((entry[0] - 48) - 1)].GetInfo("last_name") << std::endl;
			std::cout << "Nickname : " << _contacts[(int)((entry[0] - 48) - 1)].GetInfo("nick_name") << std::endl;
			std::cout << "Phone number : " << _contacts[(int)((entry[0] - 48) - 1)].GetInfo("phone_number") << std::endl;
			std::cout << "Darkest secret : " << _contacts[(int)((entry[0] - 48) - 1)].GetInfo("darkest_secret") << std::endl;
			return ;
		}
	}

}

void	PhoneBook::DisplayPhoneBook()
{
	std::string	fname;
	std::string	lname;
	std::string	nname;

	for (int j = 0; j < 8 && !_contacts[j].GetInfo("first_name").empty(); j++)
	{
		fname = _contacts[j].GetInfo("first_name");
		lname = _contacts[j].GetInfo("last_name");
		nname = _contacts[j].GetInfo("nick_name");

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
		std::cout << "|" << std::setw(10) << nname << std::endl;
	}
}