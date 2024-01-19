#include "cub3d.h"

int	check_nb(char **txt)
{
	if (txt[0] && txt[1] && txt[2]
		&& txt[3] && txt[4] && txt[5])
		return (1);
	return (0);
}

int	check_dir_line(char *s, t_txt *txt)
{
	int	i;

	if ((ft_strncmp(line, "NO ", 3) == 0)
		fill_txt(line, NO, txt);
	else if (ft_strncmp(line, "SO ", 3) == 0))
		fill_txt(line, SO, txt);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		fill_txt(line, EA, txt);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		fill_txt(line, WE, txt);
	else if (ft_strncmp(line, "C ", 2) == 0)
		fill_txt(line, C, txt);
	else if (ft_strncmp(line, "F ", 2) == 0)
		fill_txt(line, F, txt);
	else
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '1' || s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W' || s[i++] == 'S')
				return (0);
		}
	}
	return (1);
}

int	check_map_viable(char **map)
{
	char	*line;
	int	fd;
	t_txt	*txt;

	txt->txt = ft_calloc(7 * sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && (check_nb(txt->txt) != 1))
	{
		if (check_dir_line(line, txt) == 0)
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