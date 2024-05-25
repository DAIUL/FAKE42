#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe< std::vector<int> > merge = PmergeMe< std::vector<int> >();

	if (ac < 3) {
		std::cout << "Error : Missing arguments, enter at least 2 numbers" << std::endl;
		return 0;
	}
	for (int i = 1; av[i]; i++) {
 		if (!merge.checkNum(av, i, ac))
			return 0;
	}
	merge.fillPool(av);
	merge.displayPool(merge.getPool());
	merge.displayTime();
	merge.sortPool();
	return 0;
}