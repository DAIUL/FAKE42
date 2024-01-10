#include "cub3d.h"
#include <stdio.h>

int	parsing_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if ((map[i] == '.') && (map[i + 1] == 'c') && (map[i + 2] == 'u') && (map[i + 3] == 'b'))
		return (printf("youpi\n"), 1);
	else
		return (printf("non\n"), 0);
}