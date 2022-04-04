/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:31:19 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:06:04 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_init_scene_2(t_scene	*scene)
{
	scene->move.up = 0;
	scene->move.down = 0;
	scene->move.left = 0;
	scene->move.right = 0;
	scene->move.turn_left = 0;
	scene->move.turn_right = 0;
	scene->start_pos.x = 0;
	scene->start_pos.y = 0;
	scene->start_dir.x = 0;
	scene->start_dir.y = 0;
	scene->start_plane.x = 0;
	scene->start_plane.y = 0;
	scene->pos_door.w = 0;
	scene->pos_door.h = 0;
	scene->touch_wall.w = 0;
	scene->touch_wall.h = 0;
	scene->pars.sp2 = 0;
	scene->pars.sp3 = 0;
	scene->pars.sp4 = 0;
	scene->pars.fl5 = 0;
	scene->pars.dr6 = 0;
	scene->pars.ex7 = 0;
}

void	ft_init_scene(t_scene	*scene)
{
	int	i;

	i = 0;
	ft_bzero(scene, sizeof(scene));
	scene->tex = ft_calloc(sizeof(char *), NB_TEXTURES);
	scene->textures = ft_calloc(sizeof(t_img *), NB_TEXTURES);
	while (i < 10)
		scene->tex[i++] = NULL;
	scene->size.w = -1;
	scene->pos.x = -1;
	scene->pos.y = -1;
	scene->dir.x = -1;
	scene->dir.y = -1;
	scene->mouse = ft_calloc(sizeof(t_mouse), 1);
	scene->mouse->lkm_is_pressed = 0;
	scene->mouse->rkm_is_pressed = 0;
	scene->nb_textures = 4;
	scene->floor = NULL;
	scene->ceil = NULL;
	scene->map = NULL;
	ft_init_scene_2(scene);
}
