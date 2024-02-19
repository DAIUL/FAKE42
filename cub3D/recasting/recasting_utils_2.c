# include "cub3d.h"

void	ft_free_buffer(t_txt *txt)
{
	int	y;

	y = 0;
	if (txt->buffer)
	{
		while (y < screenHeight)
		{
			free(txt->buffer[y]);
			y++;
		}
		free(txt->buffer);
	}
}