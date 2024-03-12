#include "Harl.hpp"

Harl::Harl()
{
	lvl[0] = "DEBUG";
	lvl[1] = "INFO";
	lvl[2] = "WARNING";
	lvl[3] = "ERROR";
}

Harl::~Harl()
{
}

void	Harl::_debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}

void	Harl::_info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
	
void	Harl::_warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::_error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int	Harl::which_lvl(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == lvl[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	for (int i = which_lvl(level); i < 4; i++)
	{
		switch(i)
		{
			case 0:
				_debug();
				break ;
			case 1:
				_info();
				break ;
			case 2:
				_warning();
				break ;
			case 3:
				_error();
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		if (i == -1)
			break ;
	}
}