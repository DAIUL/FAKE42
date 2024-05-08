#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
//BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { ? };
BitcoinExchange::~BitcoinExchange() {};

// BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & src)
// {
// 	if (this != &src)
// 	{
		
// 	}
// 	return *this;
// }

void	BitcoinExchange::dataBase()
{
	std::map<std::string, double>	database;
	std::ifstream	dataFile("data.csv");
	std::string		line;
    std::stringstream stream;
    std::string date;
    double value;

	if (!dataFile.is_open()) {
		std::cerr << "data.csv does not exist..." << std::endl;
		return ;
	}
	 while (std::getline(dataFile, line)) {
		std::stringstream stream(line);

		if (std::getline(stream, date, ',') && stream >> value)
            database[date] = value;
	}
	
	_database = database;
}

void	BitcoinExchange::showResult(std::string line)
{
	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 7).c_str());
	int	day = atoi(line.substr(8, 10).c_str());

	// cherche la date dans la db si elle y est pas tu recule jusqu'a trouver une date 
}

bool	BitcoinExchange::checkInput(std::string line)
{
	if (line.find(" | ") != 10) {
		std::cout << "Error : wrong format input, should be : [date] | [value]" << std::endl;
		return false;
	}

	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 7).c_str());
	int	day = atoi(line.substr(8, 10).c_str());

	if (!(((year >= 2009) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31))
			|| (year == 2009 && month == 1 && day == 1))) {
		std::cout << "Error : bad date input => " << line.substr(0, 10) << std::endl;
		return false;
	}

	float	value = atof(line.substr(13).c_str());
	std::cout << value << std::endl;

	// for (int i = 13; line[i]; i++) {
	// 	std::cout << i << line[i];
	// 	if (!isdigit(line[i])/* && line[i] != '-' && line[i] != '.'*/) {
	// 		std::cout << "Error : bad value input A" << std::endl;
	// 		return false;
	// 	}
	// 	else if (line[i] == '-' && i != 13) {
	// 		std::cout << "Error : bad value input" << std::endl;
	// 		return false;
	// 	}
	// }

	if (value < 0) {
		std::cout << "Error : not a positive number" << std::endl;
		return false;
	}
	else if (value > 1000) {
		std::cout << "Error : too large number" << std::endl;
		return false;
	}

	return true;
}

void	BitcoinExchange::exchange() {
	std::map<std::string, double>	input;
	std::ifstream	inputFile("input.txt");
	std::string		line;

	if (!inputFile.is_open()) {
		std::cerr << "input.txt does not exist..." << std::endl;
		return ;
	}
	 while (std::getline(inputFile, line)) {
		if (checkInput(line))
			showResult(line);
	}

// 	for (std::map<std::string, double>::iterator it = input.begin(); it != input.end(); ++it) {
//         std::cout << "Date : " << it->first << " | Value : " << it->second << std::endl;
// 	}
}
