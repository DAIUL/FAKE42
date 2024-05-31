#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe< std::deque<int> > merge = PmergeMe< std::deque<int> >();

	if (ac < 3) {
		std::cout << "Error : Missing arguments, enter at least 2 numbers" << std::endl;
		return 0;
	}
	for (int i = 1; av[i]; i++) {
 		if (!merge.checkNum(av, i))
			return 0;
	}
	merge.fillPool(av);
	merge.displayPool(merge.getPool());
	merge.sortPool();
	merge.displayTime();
	merge.displayPool(merge.getRes());

	return 0;
}