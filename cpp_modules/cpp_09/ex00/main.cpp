#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	bitcoin;
	
	if (ac != 2) {
		std::cerr << "Wrong amount of arguments, format must be : ./btc [file]" << std::endl;
		return 0;
	}
	bitcoin.dataBase();
	bitcoin.exchange(av[1]);
	return 0;
}