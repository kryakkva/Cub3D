/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:12:25 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 18:48:36 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define BUFFER_SIZE	 2048

# define HEIGHT			1050
# define WIDTH			1680

typedef int	t_bool;
# define FALSE 			0
# define TRUE  			1

# define OPEN_ERROR		-1
# define PARSE_ERROR	-2
# define MLX_ERROR		-3

# define THETA			0.05
# define SPEED_MOVE		0.20
# define FOV			0.66

# define NB_TEXTURES	4

# define SOUTH			0
# define EAST			1
# define NORTH			2
# define WEST			3

# define ESC			53
# define ARROW_LEFT		123
# define ARROW_RIGHT	124
# define ARROW_UP		126
# define ARROW_DOWN		125
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14

typedef struct s_int
{
	int			w;
	int			h;
}				t_int;

typedef struct s_double
{
	double		x;
	double		y;
}				t_double;

typedef struct s_dda
{
	t_int		coord;
	t_int		step;
	t_int		draw;
	t_double	side_dist;
	t_double	delta_dist;
	t_double	ray_dir;
	int			side;
	int			line;
	int			line_height;
	double		perpwalldist[WIDTH];
}				t_dda;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_draw
{
	t_int		start;
	t_double	end;
	int			length;
	int			color;
}				t_draw;

typedef struct s_texdata
{
	int			length;
	double		step;
	int			texx;
	double		texpos;
	int			texy;
	t_int		tex_size;
}				t_texdata;

typedef struct s_move
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			turn_left;
	int			turn_right;
}				t_move;

typedef struct s_mouse
{
	int			lkm_is_pressed;
	int			rkm_is_pressed;
	int			x;
	int			y;
	int			previous_x;
	int			previous_y;
}				t_mouse;

typedef struct s_img
{
	void		*img_ptr;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_int		size;
}				t_img;

typedef struct s_scene
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**tex;
	t_img		*textures[NB_TEXTURES];
	t_rgb		*floor;
	t_rgb		*ceil;
	char		**map;
	t_int		size;
	t_double	pos;
	t_double	dir;
	t_double	plane;
	t_move		move;
}				t_scene;

void	ft_join_and_clean(char **str1, char *str2);
void	ft_skip_empty_lines(int fd, char **line);
int		ft_only_space_lines(char *line);
void	ft_offset(t_double *dir, double angle);

int		ft_open(char *map);
int		ft_close(t_scene *scene);
int		ft_ext(char *name);

int		get_next_line(int fd, char **line);

void	ft_print_error(char *str, int err);
void	ft_free_mem(void *ptr);
void	ft_free_array(char **mass);
int		ft_mass_len(char **mass);
int		ft_max_len_str(char **mass);

void	ft_init_scene(t_scene	*scene);
void	ft_start_pos_init(t_scene *scene, char **map, int line, int col);

void	ft_set_color(t_scene *scene, char **data, int code);

t_scene	*ft_start_check(int argc, char **argv);

void	ft_parse_map(t_scene *scene, int fd);

void	ft_check_map(char **map, t_int size);
int		ft_verif_map(char **map, t_int el);

void	ft_parse_textures(t_scene *scn);

int		ft_key_hook(int keycode, t_scene *scene);
void	ft_move(t_scene	*scene);
int		ft_refresh(t_scene *scene);
int		ft_key_release(int keycode, t_move *move);

void	ft_move_up(t_scene *scene);
void	ft_move_down(t_scene *scene);
void	ft_move_left(t_scene *scene);
void	ft_move_right(t_scene *scene);
void	ft_turn_left(t_scene *scene);
void	ft_turn_right(t_scene *scene);

void	ft_draw_image(t_scene *scene);
void	ft_set_draw_start_end(t_dda *dda, t_scene *scene);
void	ft_draw_wall(char *data, t_dda *dda, t_scene *scene);
int		ft_rgb_to_int(t_rgb rgb);

void	ft_put_pixel(char *data, t_draw draw, int color);
void	ft_put_texture(char *data, t_draw draw, char *texdata);

#endif
