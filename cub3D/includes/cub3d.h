#ifndef CUB3D_H
# define CUB3D_H
# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define F 4
# define C 5

# include "../libft/libft.h"

typedef struct s_txt
{
	char	**txt;
}				t_txt;

int		parsing_map(char *map);
int		check_nb(t_txt *txt);
int		check_dir_line(char *s, t_txt *txt);
int		check_map_viable(char *map);
int		len_txt(int i, char *s);
void	fill_txt(char *s, int id, t_txt *txt);

#endif