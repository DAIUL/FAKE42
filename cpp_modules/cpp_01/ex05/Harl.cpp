#include "Harl.hpp"

Harl::Harl()
{
	lvl[0] = "DEBUG";
	lvl[1] = "INFO";
	lvl[2] = "WARNING";
	lvl[3] = "ERROR";
	ptr[0] = &Harl::_debug;
	ptr[1] = &Harl::_info;
	ptr[2] = &Harl::_warning;
	ptr[3] = &Harl::_error;
}

Harl::~Harl()
{
}

void	Harl::_debug(void) {
	std::cout << "~DEBUG~" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::_info(void) {
	std::cout << "~INFO~" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
	
void	Harl::_warning(void) {
	std::cout << "~WARNING~" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void) {
	std::cout << "~ERROR~" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (lvl[i] == level)
		{
			(this->*ptr[i])();
			break ;
		}
		else if (i == 3)
			std::cout << "Nothing to complain about ?" << std::endl;
	}
}