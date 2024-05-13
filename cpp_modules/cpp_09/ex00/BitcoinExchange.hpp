#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double>	_database;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange();

	BitcoinExchange&	operator=(BitcoinExchange const & src);

	void	dataBase();
	void	exchange(char *txt);
	bool	checkInput(std::string line);
	void	showResult(std::string line);
	bool	stoi(const std::string &str);
};

#endif