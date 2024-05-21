#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <list>

class PmergeMe
{
private:
	std::vector<int>	_basePool;
	std::list<int>		_minVec;
	std::list<int>		_maxVec;
public:
	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();

	void	fillPool(char **const &av);
	bool	checkNum(char** const & av, int const & i);
	bool	stoi(const std::string &str);
	void	displayPool();

	PmergeMe&	operator=(PmergeMe const & src);
};

#endif