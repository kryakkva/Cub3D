/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_wall_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 20:20:58 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 21:48:42 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_touch_wall_ud(t_scene *s)
{
	if (s->touch_wall.w == UP)
	{
		if (s->map[(int)(s->pos.x - s->dir.x * SPEED_MOVE * JUMP)] \
		[(int)s->pos.y] == '0')
			s->pos.x = s->pos.x - s->dir.x * SPEED_MOVE * JUMP;
	}
	else if (s->touch_wall.w == DOWN)
	{
		if (s->map[(int)(s->pos.x + s->dir.x * SPEED_MOVE * JUMP)] \
		[(int)s->pos.y] == '0')
			s->pos.x = s->pos.x + s->dir.x * SPEED_MOVE * JUMP;
	}
	if (s->touch_wall.h == UP)
	{
		if (s->map[(int)s->pos.x][(int)(s->pos.y - \
		s->dir.y * SPEED_MOVE * JUMP)] == '0')
			s->pos.y = s->pos.y - s->dir.y * SPEED_MOVE * JUMP;
	}
	else if (s->touch_wall.h == DOWN)
	{
		if (s->map[(int)s->pos.x][(int)(s->pos.y + \
		s->dir.y * SPEED_MOVE * JUMP)] == '0')
			s->pos.y = s->pos.y + s->dir.y * SPEED_MOVE * JUMP;
	}
}

static void	ft_touch_wall_lr(t_scene *s)
{
	if (s->touch_wall.w == LEFT)
	{
		if (s->map[(int)(s->pos.x - s->plane.x * SPEED_MOVE * JUMP)] \
		[(int)s->pos.y] == '0')
			s->pos.x = s->pos.x - s->plane.x * SPEED_MOVE * JUMP;
	}
	else if (s->touch_wall.w == RIGHT)
	{
		if (s->map[(int)(s->pos.x + s->plane.x * SPEED_MOVE * JUMP)] \
		[(int)s->pos.y] == '0')
			s->pos.x = s->pos.x + s->plane.x * SPEED_MOVE * JUMP;
	}
	if (s->touch_wall.h == LEFT)
	{
		if (s->map[(int)s->pos.x] \
		[(int)(s->pos.y - s->plane.y * SPEED_MOVE * JUMP)] == '0')
			s->pos.y = s->pos.y - s->plane.y * SPEED_MOVE * JUMP;
	}
	else if (s->touch_wall.h == RIGHT)
	{
		if (s->map[(int)s->pos.x] \
		[(int)(s->pos.y + s->plane.y * SPEED_MOVE * JUMP)] == '0')
			s->pos.y = s->pos.y + s->plane.y * SPEED_MOVE * JUMP;
	}
}

static void	ft_restore_position(t_scene *scene)
{
	if (scene->pos_door.w && scene->pos_door.h)
		scene->map[scene->pos_door.w][scene->pos_door.h] = '6';
	scene->pos = scene->start_pos;
	scene->dir = scene->start_dir;
	scene->plane = scene->start_plane;
	ft_offset(&scene->plane, 1.570796);
	scene->touch_wall.w = 0;
	scene->touch_wall.h = 0;
	scene->touch_nbr = 0;
	scene->dark = 0;
	ft_refresh(scene);
}

void	ft_touch_sp(t_scene *scene, int x, int y)
{
	if (scene->map[x][y] == '3')
		ft_restore_position(scene);
	else if (scene->map[x][y] == '4')
	{
		scene->map[x][y] = '0';
		scene->pars.sp4--;
		free(scene->menu);
		scene->menu = ft_itoa(scene->pars.sp4);
	}
}

void	ft_touch_wall(t_scene *scene)
{	
	scene->dark--;
	if (scene->dark < 0)
		scene->dark = 0;
	if (scene->touch_wall.w || scene->touch_wall.h)
	{
		scene->touch_nbr++;
		scene->dark = DARK_TIME;
		ft_touch_wall_ud(scene);
		ft_touch_wall_lr(scene);
		ft_refresh(scene);
		scene->touch_wall.w = 0;
		scene->touch_wall.h = 0;
	}
	if (scene->touch_nbr == 5)
		ft_restore_position(scene);
	ft_refresh(scene);
}
