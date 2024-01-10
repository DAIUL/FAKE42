#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2)
		parsing_map(av[1]);
	else
		return (0);
}