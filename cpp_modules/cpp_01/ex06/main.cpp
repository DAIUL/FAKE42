#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl = Harl();
	if (ac == 2)
	{
		harl.complain(std::string(av[1]));
	}
	else
		std::cout << "Invalid arguments" << std::endl;
	return (0);
}