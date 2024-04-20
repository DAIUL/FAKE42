#include "iter.hpp"

template<typename T>
void	appli(T &elem)
{
	elem += 1;
	std::cout << elem << std::endl;
}

int	main(void)
{
	char	str[6] = "salut";
	int		arr[5] = {1, 2, 3, 4, 5};
	double	darr[5] = {1, 2, 3, 4, 5};

	iter(str, 6, &appli);
	iter(arr, 5, &appli);
	iter(darr, 5, &appli);

	return 0;
}