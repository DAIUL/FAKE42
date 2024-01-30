# include "cub3d.h"

int	check_line_vert(char **s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i][j])
	{
		TEST1
		i = 0;
		while (s[i][j])
		{
			if (s[i][j] == ' ' && (s[i + 1][j] != ' ' && s[i + 1][j] != '1'
				&& s[i + 1][j] != '\0'))
				return (ft_printf("map ouverte\n"), 0);
			if ((s[i][j] == 'N' || s[i][j] == 'E' || s[i][j] == 'W' || s[i][j] == 'S')
				&& (s[i + 1][j] != '0' && s[i + 1][j] != '1'))
				return (ft_printf("map ouverte\n"), 0);
 			if (s[i][j] == '0'	
				&& (s[i + 1][j] != 'N' && s[i + 1][j] != 'E' && s[i + 1][j] != 'W'
				&& s[i + 1][j] != 'S' && s[i + 1][j] != '1' && s[i + 1][j] != '0'))
				return (ft_printf("map ouverte\n"), 0);
			i++;
		}
		j++;
	}
	return (1);
}