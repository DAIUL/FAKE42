#include "cub3d.h"

int	len_txt(int i, char *s)
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

void	fill_txt(char *s, int id, t_txt *txt)
{
	int	i;

	i = 2;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] && s[i] != '\n')
		txt->txt[id] = ft_strndup(s, i, len_txt(i, s));
	return ;
}