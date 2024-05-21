#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const & src) {*this = src;}
PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(PmergeMe const & src) {
	if (this != &src)
	{
		_basePool = src._basePool;
	}
	return *this;
}

void	PmergeMe::fillPool(char **const & av) {
	std::vector<int>	filled;

	for (int i = 1; av[i]; i++) {
			filled.push_back(atoi(av[i]));
	}
	_basePool = filled;
}

bool	PmergeMe::checkNum(char** const & av, int const & i) {
	
	std::string	snum = av[i];

	if (!stoi(snum)) {
		std::cout << "Error : not a number" << std::endl;
		return false;
	}
	int	num = atoi(av[i]);
	if (num < 1 || num > 3000) {
		std::cout << "Error : Please enter number between 1 and 3000" << std::endl;
		return false;
	}
	for (int j = 1; j < i; j++) {
		if (atoi(av[j]) == num) {
			std::cout << "Error : Double number" << std::endl;
			return false;
		}
	}
	return true;
}

bool	PmergeMe::stoi(const std::string &str)
{
	int					num;
	std::istringstream	iss(str);

	iss >> std::noskipws;
	iss>> num;

	if (iss.fail() || !iss.eof()) {
		return false;
	}
	return true;
}

void	PmergeMe::displayPool() {
	
	std::cout << "Before : ";

	for (std::vector<int>::iterator it = _basePool.begin(); it != _basePool.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}