#include "cub3d.h"
#include <stdio.h>

int	parsing_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i -= 4;
	if ((map[i] == '.') && (map[i + 1] == 'c')
		&& (map[i + 2] == 'u') && (map[i + 3] == 'b'))
		check_map_viable(map);
	else
		return (printf("non\n"), 0);
	return (1);
}

// char	*remove_nl(char *line);
// {
// 	int	i;
// 	char	*clear;

// 	i = 0;
// 	clear = ft_calloc(ft_strlen(line), sizeof(char));
// 	while (line[i] && (line[i] != '\n'))
// 		clear[i] = line[i++];
// 	free(line);
// 	return (clear);
// }

// char	**copy_map(char **map, int lect, char **av)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	fd = open(av, O_RDONLY);
// 	while (i < lect)
// 	{
// 		line = get_next_line(fd);
// 		map[i++] = remove_nl(line);
// 	}
// 	close(fd);
// 	map[i] = ft_calloc(1, sizeof(char)); 
// 	return (map);
// }

// char	**map_size(int ac, char **av)
// {
// 	char	**map;
// 	int		lect;
// 	int		fd;
// 	char	*line;

// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		ERROR
// 	lect = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		lect++;
// 	}
// 	free(line);
// 	map = ft_calloc((lect + 1), sizeof(char *));
// 	close(fd);
// 	map = copy_map(map, lect, av[1]);
// 	return (map);
// }