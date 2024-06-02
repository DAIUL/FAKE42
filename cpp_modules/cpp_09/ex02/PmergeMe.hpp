#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>


template<typename T>
class PmergeMe
{
private:
	T			_basePool;
	T			_minList;
	T			_maxList;
	T			_res;
	double 		_time;
	std::string	_name;
public:
	PmergeMe();
	PmergeMe(PmergeMe const & src);
	~PmergeMe();

	void	fillPool(char **const &av);
	bool	checkNum(char** const & av, int const & i);
	bool	stoi(const std::string &str);
	void	sortPool();
	void	displayPool(T array, std::string when) const;
	void 	displayTime() const;

	T		getPool() const;
	T		getMin() const;
	T		getMax() const;
	T		getRes() const;
	void	setName();

	PmergeMe&	operator=(PmergeMe const & src);
};

#endif