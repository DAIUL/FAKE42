/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:59:04 by qpuig             #+#    #+#             */
/*   Updated: 2024/01/27 16:59:04 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define NO 0
# define SO 1
# define EA 2
# define WE 3
# define F 4
# define C 5

# define TEST1 ft_printf("-----------TEST1-----------\n");
# define TEST2 ft_printf("-----------TEST2-----------\n");
# define TEST3 ft_printf("-----------TEST3-----------\n");

# include "../libft/libft.h"

typedef struct s_txt
{
	char	**txt;
	int		start;
	size_t	max_len;
	size_t	map_line;
	size_t	lect;
}				t_txt;

int		parsing_map(char *map);
int		check_nb(t_txt *txt);
int		check_dir_line(char *s, t_txt *txt);
int		check_map_viable(char *map);
int		len_txt(int i, char *s);
void	fill_txt(char *s, int id, t_txt *txt);
int		skip_till_elem(char *s);
int		check_map_line(char **s, t_txt *txt);
int		open_map(char *s, int i);
int		end_map(char *s);
char	*remove_nl(char *line, t_txt *txt);
char	**map_size(char *premap, t_txt *txt);
char	**copy_map(char **map, t_txt *txt, char *premap);
int		map_line_v(char *s);
int		check_line_vert(char **s);

#endif