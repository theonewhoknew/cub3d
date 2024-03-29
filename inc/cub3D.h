/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:22:25 by dtome-pe          #+#    #+#             */
/*   Updated: 2024/01/23 11:52:51 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define W 640
# define H 480
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/*mac macros*/
# define ESC 53
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ROTRIGHT 124
# define ROTLEFT 123

/*linux macros*/
/* # define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ROTRIGHT 65363
# define ROTLEFT 65361 */

# include "../libft/libft.h"
# include "../mlx_macos/mlx.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_map
{
	char			*line;
	struct s_map	*next;

}				t_map;

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			line;
	int			endian;
	int			w;
	int			h;
	char		*p;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_cub
{
	/*minilibx*/
	t_mlx	*mlx;

	/*map parsing - checking*/
	char	*path;
	char	*n_p;
	char	*s_p;
	char	*w_p;
	char	*e_p;
	char	*ceiling_color;
	char	*floor_color;
	t_map	*map_list;
	char	**map;
	int		*line_len;
	int		char_pos;
	size_t	longest;

	/*raycasting calculations*/
	t_vec	pos;
	t_vec	dir;
	t_vec	pl;
	t_vec	ray;
	t_vec	ray_map;
	t_vec	dist;
	t_vec	delta_dist;
	double	camera;
	int		step_x;
	int		step_y;
	int		hit;
	int		hit_side;
	int		hit_direction;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	m;
	double	r;
	char	pos_char;

	/*nuevas variables*/
	double	wall_x;
	int		text_x;
	int		text_y;
	double	step;
	double	text_pos;

	/*floor-ceiling cast*/
	char	**f_rgb;
	char	**c_rgb;
	int		f_color;
	int		c_color;		

	/*game images*/
	t_img	*n;
	int		n_w;
	int		n_h;
	t_img	*s;
	int		s_w;
	int		s_h;
	t_img	*w;
	int		w_w;
	int		w_h;
	t_img	*e;
	int		e_w;
	int		e_h;
}			t_cub;

/*parse - check*/
void	init_parse(t_cub *cub, char **argv);

int		check_argv(int argc, char **argv);
int		check_extension(char *file, char *extension);
int		check_elements(t_cub *cub);
int		parse(t_cub *cub);
int		get_map(t_cub *cub, char *line, int fd);
int		there_is_map(t_cub *cub);
int		pos_char(char c);
int		check(t_cub *cub);
int		check_color(t_cub *cub, char *color, char *type);
int		check_gaps(char **map);
int		check_map(char **map);
int		check_single(char **map, int *line_len);
int		check_textures(t_cub *cub);
int		get_length(char **map);
int		get_height(char **map);
int		is_pos(char c);

/*game - raycasting*/
void	init_game(t_cub *cub, t_mlx *mlx);
void	game(t_cub *cub);
void	draw(t_cub *cub, int w, t_img *frame);
int		render_loop(t_cub *cub);

void	draw_floor_ceiling(t_cub *cub, t_img *frame);
void	free_cub(t_cub *cub);

/*keys*/
int		key_press(int key, t_cub *cub);
int		x_press(void);

/*map utils*/

void	print_map(t_map *map);
void	print_map2(char **map);
t_map	*ft_mapnew(char *content);
void	ft_mapback(t_map **lst, t_map *new);
t_map	*ft_maplast(t_map *lst);
void	ft_mapclear(t_map **lst);
int		count_list(t_map *map);
size_t	ft_padcpy(char *dst, const char *src, size_t dstsize);

/*print utils*/
void	print_cub(t_cub *cub);
void	print_vector(t_vec *vec);
int		print_error(char *str);
void	print_img_info(t_cub *cub);

/*vector utils*/
void	vector(t_vec *vec, double x, double y);

/*mlx utils*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif