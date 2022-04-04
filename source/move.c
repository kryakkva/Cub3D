/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:28:59 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 17:57:42 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_up(t_scene *scene)
{
	if (scene->map[(int)(scene->pos.x + scene->dir.x * SPEED_MOVE)] \
	[(int)scene->pos.y] == '0')
		scene->pos.x = scene->pos.x + scene->dir.x * SPEED_MOVE;
	if (scene->map[(int)scene->pos.x] \
	[(int)(scene->pos.y + scene->dir.y * SPEED_MOVE)] == '0')
		scene->pos.y = scene->pos.y + scene->dir.y * SPEED_MOVE;
	ft_refresh(scene);
}

void	ft_move_down(t_scene *scene)
{
	if (scene->map[(int)(scene->pos.x - scene->dir.x * SPEED_MOVE)] \
	[(int)scene->pos.y] == '0')
		scene->pos.x = scene->pos.x - scene->dir.x * SPEED_MOVE;
	if (scene->map[(int)scene->pos.x] \
	[(int)(scene->pos.y - scene->dir.y * SPEED_MOVE)] == '0')
		scene->pos.y = scene->pos.y - scene->dir.y * SPEED_MOVE;
	ft_refresh(scene);
}

void	ft_move_left(t_scene *scene)
{
	if (scene->map[(int)(scene->pos.x + scene->plane.x * SPEED_MOVE)] \
	[(int)scene->pos.y] == '0')
		scene->pos.x = scene->pos.x + scene->plane.x * SPEED_MOVE;
	if (scene->map[(int)scene->pos.x] \
	[(int)(scene->pos.y + scene->plane.y * SPEED_MOVE)] == '0')
		scene->pos.y = scene->pos.y + scene->plane.y * SPEED_MOVE;
	ft_refresh(scene);
}

void	ft_move_right(t_scene *scene)
{
	if (scene->map[(int)(scene->pos.x - scene->plane.x * SPEED_MOVE)] \
	[(int)scene->pos.y] == '0')
		scene->pos.x = scene->pos.x - scene->plane.x * SPEED_MOVE;
	if (scene->map[(int)scene->pos.x] \
	[(int)(scene->pos.y - scene->plane.y * SPEED_MOVE)] == '0')
		scene->pos.y = scene->pos.y - scene->plane.y * SPEED_MOVE;
	ft_refresh(scene);
}
