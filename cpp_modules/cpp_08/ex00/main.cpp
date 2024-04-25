#include "easyfind.hpp"
#include <list>
#include <vector>

int	main()
{
	std::vector<int> vector;
	std::list<int> list;

	vector.push_back(598);
	vector.push_back(2);
	vector.push_back(0);
	vector.push_back(1866513);
	vector.push_back(59);
	vector.push_back(7);

	list.push_back(598);
	list.push_back(2);
	list.push_back(0);
	list.push_back(1866513);
	list.push_back(59);
	list.push_back(7);

	easyfind(vector, 598);
	easyfind(vector, 3);
	
	easyfind(list, 2);
	easyfind(list, 89);

	return 0;
}