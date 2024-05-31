#include "PmergeMe.hpp"

template<typename T>
PmergeMe<T>::PmergeMe() {}

template<typename T>
PmergeMe<T>::PmergeMe(PmergeMe const & src) {*this = src;}

template<typename T>
PmergeMe<T>::~PmergeMe() {}

template<typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(PmergeMe const & src) {
	if (this != &src)
	{
		_basePool = src._basePool;
		_minList = src._minList;
		_maxList = src._maxList;
	}
	return *this;
}

template<typename T>
void	PmergeMe<T>::fillPool(char **const & av) {
	T	filled;

	for (int i = 1; av[i]; i++) {
			filled.push_back(atoi(av[i]));
	}
	_basePool = filled;
}

template<typename T>
bool	PmergeMe<T>::checkNum(char** const & av, int const & i) {
	
	std::string	snum = av[i];

	if (!stoi(snum)) {
		std::cout << "Error : not a number" << std::endl;
		return false;
	}
	int	num = atoi(av[i]);
	if (num < 1) {
		std::cout << "Error : Please enter a positive number" << std::endl;
		return false;
	}
	for (int j = 1; j < i; j++) {
		if (atoi(av[j]) == num) {
			std::cout << "Error : Double number" << std::endl;
			return false;
		}
	}
	// for (int i = 0; av[i + 1]; i++) {
	// 	if (atoi(av[i]) < atoi(av[i + 1]) && i == (ac - 2)) {
	// 		std::cout << "Error : Already sorted" << std::endl;
	// 		return false;
	// 	}
	// }
	
	return true;
}


template<typename T>
bool	PmergeMe<T>::stoi(const std::string &str)
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

template<typename T>
void	PmergeMe<T>::displayPool(T array) const {
	std::cout << "Before : ";

	for (typename T::iterator it = array.begin(); it != array.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe<T>::sortPool() {

	int	i;
	int	j;

	std::clock_t	start = std::clock();

	for ( i = 0; _basePool[i + 1]; i += 2) {
		if (_basePool[i] > _basePool[i + 1]) {
			_minList.push_back(_basePool[i + 1]);
			_maxList.push_back(_basePool[i]);
		}
		else {
			_maxList.push_back(_basePool[i + 1]);
			_minList.push_back(_basePool[i]);
		}
	}
	if (_basePool[i])
		_minList.push_back(_basePool[i]);
	std::sort(_maxList.begin(), _maxList.end());
	std::sort(_minList.begin(), _minList.end());
	
	i = 0;
	j = 0;
	while (_minList[i] && _maxList[j]) {
		if (_minList[i] > _maxList[j])
			_res.push_back(_maxList[j++]);
		else
			_res.push_back(_minList[i++]);
	}
	while (_minList[i])
		_res.push_back(_minList[i++]);
	while (_maxList[j])
		_res.push_back(_maxList[j++]);

	_time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template<typename T>
void PmergeMe<T>::displayTime() const {
	std::cout << "Time to process a range of " << _basePool.size();
	std::cout << " elements with std::";
	std::cout << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

template<typename T>
T	PmergeMe<T>::getPool() const {return _basePool;}

template<typename T>
T	PmergeMe<T>::getMin() const {return _minList;}

template<typename T>
T	PmergeMe<T>::getMax() const {return _maxList;}

template<typename T>
T	PmergeMe<T>::getRes() const {return _res;}

template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;