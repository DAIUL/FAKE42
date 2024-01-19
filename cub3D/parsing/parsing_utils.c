#include "cub3d.h"

char	*len_txt(int i, char *s)
{
	int	j;

	j = 0;
	while (s[i] && (s[i] != '\n' && s[i] != ' ' && s[i] != '\t'))
	{
		j++;
		i++;
	}
	return (j);
}

char	*fill_txt(char	*s, int id, t_txt txt)
{
	int	i;

	i = 2;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] && s[i] != '\n')
		txt[id] = ft_strndup(s, i, len_txt(i, s));
}