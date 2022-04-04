/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:10:36 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 17:52:31 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	scene->win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, tmp);
	if (!scene->win)
		ft_print_error("Minilibx error", MLX_ERROR);
	free(tmp);
	mlx_hook(scene->win, 17, 0, ft_close, scene);
	mlx_hook(scene->win, 2, 0L, ft_key_hook, scene);
	mlx_hook(scene->win, 3, 0L, ft_key_release, &scene->move);
	ft_draw_image(scene);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img->img_ptr, 0, 0);
	mlx_loop(scene->mlx);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	scene = ft_start_check(argc, argv);
	scene->mlx = mlx_init();
	if (!scene->mlx)
		ft_print_error("Minilibx error", MLX_ERROR);
	scene->img = ft_calloc(sizeof(t_img), 1);
	scene->img->img_ptr = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (!scene->img->img_ptr)
		ft_print_error("Minilibx error", MLX_ERROR);
	scene->img->data = mlx_get_data_addr(scene->img->img_ptr,
			&(scene->img->bits_per_pixel), &(scene->img->size_line),
			&(scene->img->endian));
	if (!scene->img->data)
		ft_print_error("Minilibx error", MLX_ERROR);
	ft_parse_textures(scene);
	ft_start_game(scene, argv[1]);
	return (0);
}
