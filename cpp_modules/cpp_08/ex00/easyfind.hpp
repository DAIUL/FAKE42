#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
int	easyfind(T const & contain, int const & wanted)
{
	if (std::find(contain.begin(), contain.end(), wanted) != contain.end()) {
		std::cout << wanted << " is on that container !" << std::endl;
		return 1;
	}
	std::cout << wanted << " is not in that container..." << std::endl;
	return 0;
}

#endif