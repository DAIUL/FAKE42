#include "PhoneBook.hpp"

int	main()
{
	std::string	entry;
	PhoneBook	PhoneBook;
	Contact		Contact;
	
	std::cout << "===============================" << std::endl;
	std::cout << "== Welcome to your PhoneBook ==" << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "== Type ADD, SEARCH or EXIT  ==" << std::endl;
	std::cout << "========= to interact =========" << std::endl;
	std::cout << "===============================" << std::endl;
	while (1)
	{
		std::cout << "Enter a command :";
		std::getline(std::cin, entry);
		if ("ADD" == entry)
			PhoneBook.SetContact();
		else if ("SEARCH" == entry )
		{
			PhoneBook.DisplayPhoneBook();
			PhoneBook.DisplayContact();
		}
		else if ("EXIT" == entry)
			return (0);
		else
			std::cout << "Please enter a valid command" << std::endl;
	}
	return (0);
}