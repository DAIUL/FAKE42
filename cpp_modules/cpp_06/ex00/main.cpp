#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
	std::cerr << "Please enter a valid argument" << std::endl;
	return -1;
}