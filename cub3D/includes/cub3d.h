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
# include "../Minilibx/mlx.h"
# include <stdio.h>

typedef struct s_txt
{
	char	**txt;
	int		start;
	size_t	max_len;
	size_t	map_line;
	size_t	lect;
	size_t	flen;
	void	*mlx_ptr;
	void	*window;
}				t_txt;

int		parsing_map(char *map);
int		check_nb(t_txt *txt);
int		check_dir_line(char *s, t_txt *txt);
int		check_map_viable(char *map);
int		len_txt(int i, char *s);
void	fill_txt(char *s, int id, t_txt *txt);
int		skip_till_elem(char *s);
int		check_map_line(char **s, t_txt *txt);
void	check_map_line_2(char **s, t_txt *txt, int i, int j);
int		end_map(char *s);
char	*remove_nl(char *line, t_txt *txt);
char	**map_size(char *premap, t_txt *txt);
char	*map_size_2(t_txt *txt, int fd);
char	**copy_map(char **map, t_txt *txt, char *premap);
int		map_line_v(char *s, t_txt *txt);
int		check_line_vert(char **s, t_txt *txt);
void	check_line_vert_2(char **s, t_txt *txt, int i, int j);
int		start_to_map(char *map, t_txt *txt);
void	error_dir(char *s, t_txt *txt, int mes);
void	error_fd(t_txt *txt);
void	error_map(char **s, t_txt *txt, int mes);
void	file_len(t_txt *txt, char *map);
void	main_draw(t_txt *txt);

#endif