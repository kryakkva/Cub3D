/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:09:58 by apaege            #+#    #+#             */
/*   Updated: 2022/03/23 19:12:13 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_free_scene(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->size.h)
		free(scene->map[i]);
	free(scene->map);
	i = -1;
	while (++i < NB_TEXTURES)
	{
		free(scene->tex[i]);
		free(scene->textures[i]);
	}
	free(scene->tex);
	free(scene->ceil);
	free(scene->floor);
	free(scene);
}

int	ft_close(t_scene *scene)
{
	int	i;

	mlx_destroy_image(scene->mlx, scene->img->img_ptr);
	mlx_clear_window(scene->mlx, scene->win);
	mlx_destroy_window(scene->mlx, scene->win);
	i = -1;
	while (++i < NB_TEXTURES)
		mlx_destroy_image(scene->mlx, scene->textures[i]->img_ptr);
	free(scene->img);
	ft_free_scene(scene);
	exit(0);
}
