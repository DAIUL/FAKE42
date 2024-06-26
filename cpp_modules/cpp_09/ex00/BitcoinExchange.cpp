#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {*this = src;};
BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
	{
		_database.clear();
		_database = src._database;
	}
	return *this;
}

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
	float	value = atof(line.substr(13).c_str());

	//std::cout << year << "-" << month << "-" << day << std::endl;

	for (std::map<std::string, double>::iterator it = _database.begin(); it != _database.end(); it++) {
		if (line.substr(0, 10) == it->first) {
			std::cout << it->first << " => " << value << " = " << value * it->second << std::endl;
			return ;
		}
	}
	for (std::map<std::string, double>::reverse_iterator it = _database.rbegin(); it != _database.rend(); it++) {
		//std::cout << it->first << std::endl;
		if (day >= atoi(it->first.substr(8, 10).c_str())) {
			//std::cout << "le jour c'est super" << month << " it month -> " << atoi(it->first.substr(5, 7).c_str()) << std::endl;
			if (month >= atoi(it->first.substr(5, 7).c_str())) {
				//std::cout << "le mois c'est super" << std::endl;
				if (year >= atoi(it->first.substr(0, 4).c_str())) {
					std::cout << line.substr(0, 10) << " => " << value << " = " << value * it->second << std::endl;
					return ;
				}
			}
		}
	}
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

	if (!stof(line.substr(13))) {
		std::cout << "Error : not a number" << std::endl;
		return false;
	}
	float	value = atof(line.substr(13).c_str());

	// for (unsigned int i = 13; i < line.size(); i++) {
	// 	if (!std::isdigit(line[i])/* && line[i] != '-' && line[i] != '.'*/) {
	// 		std::cout << "Error : bad value input A" << std::endl;
	// 		return false;
	// 	}
	// 	else if (line[i] == '-' && i != 13) {
	// 		std::cout << "Error : bad value input" << std::endl;
	// 		return false;
	// 	}
	// }

	// if (stoi(line.substr(13).c_str())) {
	// 	std::cout << "Error : bad value input" << std::endl;
	// 	return false;
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

bool	BitcoinExchange::stof(const std::string &str)
{
	float				num;
	std::istringstream	iss(str);

	iss >> std::noskipws;
	iss>> num;

	if (iss.fail() || !iss.eof()) {
		return false;
	}
	return true;
}

void	BitcoinExchange::exchange(char *txt) {
	std::map<std::string, double>	input;
	std::ifstream	inputFile(txt);
	std::string		line;

	if (!inputFile.is_open()) {
		std::cerr << "Cannot open input file..." << std::endl;
		return ;
	}
	 while (std::getline(inputFile, line)) {
		if (line[line.size() - 1] == '\r')
			line.resize(line.size() - 1);
		if (checkInput(line))
			showResult(line);
	}
}
