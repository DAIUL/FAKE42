/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <qpuig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:15:19 by qpuig             #+#    #+#             */
/*   Updated: 2023/08/08 19:58:18 by qpuig            ###   ########.fr       */
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

typedef struct s_rats
{
	int	xr;
	int	yr;
}				t_rats;

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
	t_rats	*nbrats;
	int		step;
	int		leny;
	int		lenx;
}				t_mlx;

typedef struct s_pos
{
	int	y;
	int	x;
}				t_pos;

void	ft_check_rectangle(t_mlx *mlx);
void	ft_check_wall(t_mlx *mlx);
int	ft_check_epc(t_mlx *mlx);
t_pos	ft_pos(char **map);
int	ft_check_winable(char **map, int y, int x, int epc);
int	jab_jab_hook(int keycode, t_mlx *mlx);
void	ft_failure(t_mlx *mlx, char *message);
char	*ft_remove(char *book);
char	**ft_map(int argc, char **argv);
t_sprt	*ft_stock(void *mlx_ptr);
void	ft_display(char **map, t_mlx mlx);
void	ft_move(int x, int y, t_mlx *mlx);
int		ft_anim(t_mlx *mlx);
void	ft_posr(t_mlx *mlx, int nb);
void	ft_enemiesmvmt(t_mlx *mlx, t_rats *rats, int yr, int xr);
void	ft_enemies(t_mlx *mlx);
void	ft_animr(t_mlx *mlx, int r);
void    ft_nbrats(t_mlx *mlx);
void	ft_freesl(t_mlx *mlx);
void	ft_freeslmap(t_mlx *mlx);
void	ft_counter(t_mlx *mlx, int color);

#endif
