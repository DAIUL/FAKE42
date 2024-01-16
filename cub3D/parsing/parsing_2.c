#include "cub3d.h"

int	check_dir_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '1') || (s[i] == '0') || (s[i] == '1') || (s[i] == '1') || )
	}
}

int	check_map_viable(char **map)
{
	char	*line;
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && (check_dir_line(line) != 2))
	{
		if (check_dir_line(line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	while (line && (check_map_line) != 2)
	{
		if (check_map_line(line) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}


// mettre des statics int ou faire une structure pour garder en memoire
// les lignes deja vues