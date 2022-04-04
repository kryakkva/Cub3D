/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:07:45 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 22:03:05 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_check_exit(t_scene *scene, int x, int y)
{
	if (scene->map[x][y] == '7' && !scene->pars.sp4)
	{
		if (scene->move.space || scene->move.enter)
		{
			if (scene->argc > scene->map_num + 1)
			{
				ft_free_scene(scene);
				ft_begin(scene);
			}
			else if (scene->argc == scene->map_num + 1)
				ft_close(scene);
		}
	}
}

static void	ft_restore_door(t_scene *scene)
{
	if (((int)scene->pos.x == scene->pos_door.w + (SPEED_MOVE * DIST + 1))
		|| ((int)scene->pos.x == scene->pos_door.w - (SPEED_MOVE * DIST + 1))
		|| ((int)scene->pos.y == scene->pos_door.h + (SPEED_MOVE * DIST + 1))
		|| ((int)scene->pos.y == scene->pos_door.h - (SPEED_MOVE * DIST + 1)))
		scene->map[scene->pos_door.w][scene->pos_door.h] = '6';
}

void	ft_check_door(t_scene *scene)
{
	int	x;
	int	y;

	x = (int)(scene->pos.x + scene->dir.x * SPEED_MOVE * DIST);
	y = (int)(scene->pos.y + scene->dir.y * SPEED_MOVE * DIST);
	if (scene->map[x][y] == '6')
	{
		if (scene->move.space || scene->move.enter)
		{
			scene->pos_door.w = x;
			scene->pos_door.h = y;
			scene->map[x][y] = '0';
			ft_refresh(scene);
		}
	}
	ft_restore_door(scene);
	ft_check_exit(scene, x, y);
}
