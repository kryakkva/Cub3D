/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:10:36 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 21:31:34 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_print_error(char *str, int err)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	ft_putstr_fd("error code: ", STDERR_FILENO);
	ft_putnbr_fd(err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(err);
}

static void	ft_start_game(t_scene *scene, char *str)
{
	char	*tmp;

	tmp = ft_strdup(str);
	scene->win = mlx_new_window(scene->mlx, scene->res.w, scene->res.h, tmp);
	if (!scene->win)
		ft_print_error("Minilibx error", MLX_ERROR);
	free(tmp);
	ft_draw_image(scene);
	if (scene->dda->spr_ind)
		ft_create_sprite(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img->img_ptr, 0, 0);
	scene->menu = ft_itoa(scene->pars.sp4);
	ft_put_str_menu(scene);
	mlx_hook(scene->win, 17, 0, ft_close, scene);
	mlx_hook(scene->win, 2, 0L, ft_key_hook, scene);
	mlx_hook(scene->win, 3, 0L, ft_key_release, &scene->move);
	mlx_hook(scene->win, 4, 0, ft_mouse_press, scene);
	mlx_hook(scene->win, 5, 0, ft_mouse_release, scene);
	mlx_hook(scene->win, 6, 0, ft_mouse_hook, scene);
	mlx_loop_hook(scene->mlx, ft_refresh_sp, scene);
	mlx_loop(scene->mlx);
}

void	ft_begin(t_scene *scene)
{
	ft_start_check(scene);
	if (scene->map_num == 1)
		ft_change_resolution(scene);
	scene->mlx = mlx_init();
	if (!scene->mlx)
		ft_print_error("Minilibx error", MLX_ERROR);
	scene->img = ft_calloc(sizeof(t_img), 1);
	scene->img->img_ptr = mlx_new_image(scene->mlx, scene->res.w,
			scene->res.h);
	if (!scene->img->img_ptr)
		ft_print_error("Minilibx error", MLX_ERROR);
	scene->img->data = mlx_get_data_addr(scene->img->img_ptr,
			&(scene->img->bits_per_pixel), &(scene->img->size_line),
			&(scene->img->endian));
	if (!scene->img->data)
		ft_print_error("Minilibx error", MLX_ERROR);
	ft_parse_textures(scene);
	ft_start_game(scene, scene->argv[1]);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_calloc(sizeof(t_scene), 1);
	scene->argc = argc;
	scene->argv = argv;
	ft_begin(scene);
	return (0);
}
