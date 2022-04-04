/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekharjo <sekharjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:25:44 by apaege            #+#    #+#             */
/*   Updated: 2022/04/04 16:49:15 by sekharjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_B_H
# define CUB3D_B_H

# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <time.h>

# define BUFFER_SIZE 2048

typedef int	t_bool;
# define FALSE 				0
# define TRUE 				1

# define OPEN_ERROR			-1
# define PARSE_ERROR		-2
# define MLX_ERROR			-3
# define RES_ERROR			-4

# define THETA				0.05
# define SPEED_MOVE			0.20
# define FOV				0.66

# define MAX_WIDE			3840
# define NB_TEXTURES		10

# define SOUTH				0
# define EAST				1
# define NORTH				2
# define WEST				3
# define SPRITE2			4
# define SPRITE3			5
# define SPRITE4			6
# define FLAG				7
# define DOOR				8
# define EXIT				9

# define ESC				53
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define ARROW_UP			126
# define ARROW_DOWN			125
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_F1				122
# define KEY_F2				120
# define KEY_F3				99
# define KEY_F5				96
# define ENTER				36
# define SPACE				49
# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5

# define MAXFILENAME		35

# define RED				0x00FF0000
# define GREEN				0x0000FF00
# define BLUE				0x000000FF
# define YELLOW				0x00FFFF00
# define WHITE				0x00FFFFFF
# define AQUA				0x0000FFFF
# define OLIVE				0x00808000

# define UP					1
# define DOWN				2
# define LEFT				3
# define RIGHT				4

# define JUMP				5
# define DIST				5
# define SMOKE				40
# define DARK_TIME			5

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
	double		perpwalldist[MAX_WIDE];
	int			spr_ind;
	t_int		*sprite_pos;
	int			sprite_nbr[10];
}				t_dda;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_rgb_d
{
	double		r;
	double		g;
	double		b;
}				t_rgb_d;

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
	int			enter;
	int			space;
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

typedef struct s_pars
{
	int			sp2;
	int			sp3;
	int			sp4;
	int			fl5;
	int			dr6;
	int			ex7;
}				t_pars;

typedef struct s_scene
{
	void		*mlx;
	void		*win;
	t_img		*img;
	char		**tex;
	t_img		**textures;
	t_rgb		*floor;
	t_rgb		*ceil;
	char		**map;
	t_int		size;
	t_double	pos;
	t_double	dir;
	t_double	plane;
	t_move		move;
	int			argc;
	char		**argv;
	int			map_num;
	t_mouse		*mouse;
	t_int		res;
	int			coef;
	int			nbr_sprite;
	t_double	start_pos;
	t_double	start_dir;
	t_double	start_plane;
	int			is_wall;
	t_int		pos_door;
	t_int		touch_wall;
	int			touch_nbr;
	int			dark;
	int			nb_textures;
	t_pars		pars;
	t_dda		*dda;
	int			itter;
	int			rev;
	t_rgb_d		color_k;
	t_rgb		color_new;
	int			dark_k;
	char		*menu;
}				t_scene;

typedef struct s_sprite
{
	int			i;
	double		transform_y;
	int			spritescrx;
	int			sprite_height;
	int			sprite_width;
	int			drawstart_x;
	int			drawend_x;
	int			drawstart_y;
	int			drawend_y;
	int			tex_x;
	int			line;
}				t_sprite;

void	ft_join_and_clean(char **str1, char *str2);
void	ft_skip_empty_lines(int fd, char **line);
int		ft_only_space_lines(char *line);
void	ft_offset(t_double *dir, double angle);

void	ft_begin(t_scene *scene);
int		ft_open(char *map);
int		ft_close(t_scene *scene);
void	ft_free_scene(t_scene *scene);
int		ft_ext(char *name);

int		get_next_line(int fd, char **line);

void	ft_print_error(char *str, int err);
void	ft_free_mem(void *ptr);
void	ft_free_array(char **mass);
int		ft_mass_len(char **mass);
int		ft_max_len_str(char **mass);

void	ft_init_scene(t_scene *scene);
void	ft_start_pos_init(t_scene *scene, char **map, int line, int col);

void	ft_set_color(t_scene *scene, char **data, int code);

void	ft_start_check(t_scene *scene);

void	ft_parse_map(t_scene *scene, int fd, char *line);
void	ft_parse_bonus(int fd, t_scene *scn);
int		ft_check_line(char **data, char *type);
void	ft_get_map_utils_2(t_scene *scene, char **map, int line, int col);

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
void	ft_set_draw_start_end(t_scene *scene);
void	ft_draw_wall(char *data, t_scene *scene);
int		ft_rgb_to_int(t_rgb rgb);
t_rgb	*ft_int_to_rgb(int r, int g, int b);

void	ft_put_pixel(char *data, t_draw draw, int color, t_scene *s);
void	ft_put_texture(char *data, t_draw draw, char *texdata, t_scene *s);
void	ft_put_texture_fr(char *data, t_draw draw, char *texdata, t_scene *s);
void	ft_draw_v_line(char *data, t_draw draw, t_scene *scene);

void	ft_screenshot(char *filename, t_scene *scene);
char	*ft_scrshrt_datetime(char *res);

void	ft_draw_minimap_position(t_scene *scene);
void	ft_draw_minimap(t_scene *scene);
void	ft_print_items(t_scene *scene, int x, int y);
void	ft_square(t_scene *scene, int x, int y, int color);

int		ft_mouse_hook(int x, int y, void *param);
int		ft_mouse_press(int keycode, int x, int y, void *param);
int		ft_mouse_release(int keycode, int x, int y, void *param);

void	ft_change_resolution(t_scene *scene);

void	ft_draw_texture_line_add(char *data, t_int pos, t_scene *s);

void	ft_swap_int(int *a, int *b);
void	ft_swap_dbl(double *a, double *b);
void	ft_swap_spr(t_int *a, t_int *b);

void	ft_print_sprite(t_scene *s, t_sprite *sp);
void	ft_get_sprite(t_scene *s, int sprite_order[]);
int		ft_create_sprite(t_scene *s);
int		ft_is_sprite(t_scene *scene);
void	ft_set_sprite(t_scene *scene, char **map, int line, int col);
void	ft_set_sprite_index(t_scene *scene);

void	ft_check_door(t_scene *scene);

void	ft_touch_wall(t_scene *scene);
void	ft_touch_sp(t_scene *scene, int x, int y);
void	ft_put_pixel_tch(char *data, t_draw draw, int color, t_scene *s);
void	ft_put_texture_tch(char *data, t_draw draw, char *texdata, t_scene *s);
void	ft_put_txtr_fr_tch(char *data, t_draw draw, char *texdata, t_scene *s);

int		ft_refresh_sp(t_scene *scene);
void	ft_put_str_menu(t_scene *scene);

void	ft_set_color_coeff(t_scene *scene, t_rgb *color);
void	ft_set_color_new(t_scene *scene, t_rgb *color, int k);
void	ft_one_int_to_rgb(t_scene *s, int color);
void	ft_draw_v_line_dark(char *data, t_draw draw, t_scene *s);
void	ft_draw_v_line_dark_2(char *data, t_draw draw, t_scene *s);

#endif
