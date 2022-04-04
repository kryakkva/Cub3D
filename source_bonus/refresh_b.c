/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:08:04 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 22:06:40 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_put_str_menu(t_scene *scene)
{
	if (scene->pars.sp4)
	{
		mlx_string_put(scene->mlx, scene->win, 10, 0, WHITE, \
			"Keys needs for exit:");
		mlx_string_put(scene->mlx, scene->win, 225, 0, YELLOW, scene->menu);
	}
	else
		mlx_string_put(scene->mlx, scene->win, 10, 0, GREEN, \
			"All keys collected, exit open!");
}

int	ft_refresh(t_scene *scene)
{
	free(scene->dda->sprite_pos);
	free(scene->dda);
	ft_draw_image(scene);
	if (scene->dda->spr_ind)
		ft_create_sprite(scene);
	mlx_clear_window(scene->mlx, scene->win);
	mlx_put_image_to_window(scene->mlx, scene->win, scene->img->img_ptr, 0, 0);
	ft_put_str_menu(scene);
	return (0);
}

int	ft_refresh_sp(t_scene *scene)
{
	if (!(scene->itter % 700) && scene->dda->spr_ind)
		ft_refresh(scene);
	if (!scene->rev)
		scene->itter++;
	else
		scene->itter--;
	if (scene->itter == 3499 && !scene->rev)
		scene->rev = 1;
	if (scene->itter == 0 && scene->rev)
		scene->rev = 0;
	return (0);
}
