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
# define screenWidth 640
# define screenHeight 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define mapWidth 24
# define mapHeight 24
# define ESC 65307
# define W 119
# define Q 113
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define MS 0.045
# define RS 0.04

# define TEST1 ft_printf("-----------TEST1-----------\n");
# define TEST2 ft_printf("-----------TEST2-----------\n");
# define TEST3 ft_printf("-----------TEST3-----------\n");

# include "../libft/libft.h"
# include "../Minilibx/mlx.h"
# include <stdio.h>

typedef	struct s_img
{
	void	*ptr;
	int		*addr;
	char	*addr2;
	int		bpp;
	int		length;
	int		x;
	int		y;
	int		endian;
}				t_img;

typedef struct s_ray
{
	double	posX; 
	double	posY;
	double	dirX; 
	double	dirY;
	double	planeX;
	double	planeY;
  	double	time;
	double	oldTime;
    double	cameraX;
    double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
    double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
    double	deltaDistY;
	double	perpWallDist;
	int		stepX;
    int		stepY;
	double 	step;
	int		hit;
	int		side;
	int 	lineHeight;
	int 	drawStart;
	int 	drawEnd;
	double	wallX;
	int		texX;
	int		texY;
	double	texPos;
	int		texNum;
	int		texTmp;
	int		color;
	double	*z_buffer;
}				t_ray;

typedef struct s_txt
{
	t_ray	*ray;
	char	**txt;
	char	**fmap;
	int		start;
	size_t	max_len;
	size_t	map_line;
	size_t	lect;
	size_t	flen;
	void	*mlx_ptr;
	void	*window;
	int		mv;
	char	**tex;
	int		**buffer;
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
void	direction(t_txt *txt, char c, int y, int x);
void	raycasting(t_txt *txt);
void	setup_hit(t_txt *txt);
void	setup_sidedist(t_txt *txt);
void	setup_ray(t_txt *txt);
void	setup_draw(t_txt *txt);
void	mv_left(t_txt *txt);
void	mv_right(t_txt *txt);
void	mv_forw(t_txt *txt);
void	mv_back(t_txt *txt);
void	press_key(int keycode, t_txt *txt);
void	release_key(int keycode, t_game *game);
void	rot_cam(t_txt *txt, double rotSpeed);
void	act_move(t_txt *txt);
t_img	ft_add_img(t_txt *txt, char *path);
int		add_texture(t_txt *txt);

#endif