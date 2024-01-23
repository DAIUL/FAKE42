#include "cub3d.h"

int	check_nb(t_txt *txt)
{
	if (txt->txt[0] && txt->txt[1] && txt->txt[2]
		&& txt->txt[3] && txt->txt[4] && txt->txt[5])
		return (1);
	return (0);
}

int	check_dir_line(char *s, t_txt *txt)
{
	int	i;

	if ((ft_strncmp(s, "NO ", 3) == 0))
		fill_txt(s, NO, txt);
	else if (ft_strncmp(s, "SO ", 3) == 0)
		fill_txt(s, SO, txt);
	else if (ft_strncmp(s, "EA ", 3) == 0)
		fill_txt(s, EA, txt);
	else if (ft_strncmp(s, "WE ", 3) == 0)
		fill_txt(s, WE, txt);
	else if (ft_strncmp(s, "C ", 2) == 0)
	 	fill_txt(s, C, txt);
	 else if (ft_strncmp(s, "F ", 2) == 0)
	 	fill_txt(s, F, txt);
	else
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '1' || s[i] == '0' || s[i] == 'N'
				|| s[i] == 'E' || s[i] == 'W' || s[i++] == 'S')
				return (ft_printf("map pas au bon endroit\n"), 0);
		}
	}
	return (1);
}

int	check_map_viable(char *map)
{
	char	*line;
	int	fd;
	t_txt	txt;

	//txt = ft_calloc(1, sizeof(t_txt));
	txt.txt = ft_calloc(7, sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && (check_nb(&txt) != 1))
	{
		if (check_dir_line(line, &txt) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_nb(&txt) == 1)
		ft_printf("carre dans l'axe\n");
	// while (line && (check_map_line) != 2)
	// {
	// 	if (check_map_line(line) == 0)
	// 	{
	// 		free(line);
	// 		return (0);
	// 	}
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	return (1);
}