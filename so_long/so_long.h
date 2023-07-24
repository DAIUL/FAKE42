/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:15:19 by qpuig             #+#    #+#             */
/*   Updated: 2023/07/07 17:39:07 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include "Minilibx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <time.h>

typedef struct s_sprt
{
	void	*pointer;
	int	x;
	int	y;
	char	*pixels;
	int	bits_per_pixel;
	int	line_size;
	int	endian;
}				t_sprt;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window;
	char	**map;
	t_sprt	*sprites;
	int		tcollect;
	int		stop;
}		t_mlx;

typedef struct s_pos
{
	int	y;
	int	x;
	int	xr;
	int	yr;
}		t_pos;

void	ft_check_rectangle(char **map);
void	ft_check_wall(char **map);
int	ft_check_epc(char **map);
t_pos	ft_pos(char **map);
int	ft_check_winable(char **map, int y, int x, int epc);
int	jab_jab_hook(int keycode, t_mlx *mlx);
void	ft_failure(char *message);
char	**ft_remove(char **map);
char	**ft_map(void);
t_sprt	*ft_stock(void *mlx_ptr);
void	ft_display(char **map, t_mlx mlx);
void	ft_move(int x, int y, t_mlx *mlx);
int		ft_anim(t_mlx *mlx);
t_pos	ft_posr(char **map, int yr, int xr);
void	ft_enemiesmvmt(t_mlx *mlx, t_pos pos, int yr, int xr);
void	ft_enemies(t_mlx *mlx);
void	ft_animr(t_mlx *mlx, int r);

#endif
