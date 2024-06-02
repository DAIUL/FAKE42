#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe< std::deque<int> > Dmerge = PmergeMe< std::deque<int> >();
	PmergeMe< std::vector<int> > Vmerge = PmergeMe< std::vector<int> >();

	if (ac < 3) {
		std::cout << "Error : Missing arguments, enter at least 2 numbers" << std::endl;
		return 0;
	}
	for (int i = 1; av[i]; i++) {
 		if (!Dmerge.checkNum(av, i))
			return 0;
	}
	Vmerge.fillPool(av);
	Vmerge.displayPool(Vmerge.getPool(), "Before");
	Vmerge.sortPool();
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Vmerge.displayPool(Vmerge.getRes(), "After ");
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	Vmerge.displayTime();
	Dmerge.fillPool(av);
	Dmerge.sortPool();
	Dmerge.displayTime();

	return 0;
}