#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	bitcoin;
	(void)av;
	
	if (ac != 2) {
		std::cerr << "Wrong amount of arguments, format must be : ./btc [file]" << std::endl;
		return 0;
	}
	bitcoin.dataBase();
	bitcoin.exchange();
	return 0;
}