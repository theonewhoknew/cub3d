#ifndef CUB3D_H
# define CUB3D_H

# define W 640
# define H 480
# define ESC 65307

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


typedef struct s_cub
{
	/*minilibx*/
	void	*mlx_ptr;
	void	*win_ptr;

	/*map parsing - checking*/
	char	*path;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*ceiling_color;
	char	*floor_color;
	t_map	*map_list;
	char	**map;
	int		*line_len;
	int		char_pos;

	/*game data*/
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	t_vec	ray;
	t_vec	ray_map;
	t_vec	dist;
	t_vec	delta_dist;
	double	camera;
	int		step_x;
	int		step_y;
	int		hit;
	int		hit_side;
}			t_cub;

/*parse - check*/
void	init_parse(t_cub *cub, char **argv);

int		check_argv(int argc, char **argv);
int		parse(t_cub *cub);
int		get_map(t_cub *cub, char *line, int fd);
int		check(t_cub *cub);
int		check_color(char *color);
int		check_map(char **map, int *line_len);
int		check_single(char **map, int *line_len);
int		check_textures(t_cub *cub);
int		get_length(char **map);
int		get_height(char **map);
int		is_pos(char c);

/*game - raycasting*/
void	init_game(t_cub *cub);
void	game(t_cub *cub);

void	free_cub(t_cub *cub);

/*map utils*/

void	print_map(t_map *map);
t_map	*ft_mapnew(char *content);
void	ft_mapback(t_map **lst, t_map *new);
t_map	*ft_maplast(t_map *lst);
void	ft_mapclear(t_map **lst);

/*print utils*/
void	print_cub(t_cub *cub);
void	print_vector(t_vec *vec);

/*vector utils*/
void	vector(t_vec *vec, double x, double y);

#endif