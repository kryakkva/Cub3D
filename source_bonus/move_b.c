/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:28:59 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:13:09 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_move_up(t_scene *s)
{
	if (s->map[(int)(s->pos.x + s->dir.x * SPEED_MOVE)][(int)s->pos.y] == '0')
	{
		s->pos.x = s->pos.x + s->dir.x * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)(s->pos.x + s->dir.x * SPEED_MOVE)] \
		[(int)s->pos.y], "1567"))
			s->touch_wall.w = UP;
		else if (ft_in_charset(s->map[(int)(s->pos.x + s->dir.x * SPEED_MOVE)] \
		[(int)s->pos.y], "34"))
			ft_touch_sp(s, (int)(s->pos.x + s->dir.x * SPEED_MOVE), \
			(int)s->pos.y);
	}
	if (s->map[(int)s->pos.x][(int)(s->pos.y + s->dir.y * SPEED_MOVE)] == '0')
	{
		s->pos.y = s->pos.y + s->dir.y * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y + \
		s->dir.y * SPEED_MOVE)], "1567"))
			s->touch_wall.h = UP;
		else if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y + \
		s->dir.y * SPEED_MOVE)], "34"))
			ft_touch_sp(s, (int)s->pos.x, (int)(s->pos.y + \
			s->dir.y * SPEED_MOVE));
	}
	ft_touch_wall(s);
}

void	ft_move_down(t_scene *s)
{
	if (s->map[(int)(s->pos.x - s->dir.x * SPEED_MOVE)][(int)s->pos.y] == '0')
	{
		s->pos.x = s->pos.x - s->dir.x * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)(s->pos.x - s->dir.x * SPEED_MOVE)] \
		[(int)s->pos.y], "1567"))
			s->touch_wall.w = DOWN;
		else if (ft_in_charset(s->map[(int)(s->pos.x - s->dir.x * SPEED_MOVE)] \
		[(int)s->pos.y], "34"))
			ft_touch_sp(s, (int)(s->pos.x - s->dir.x * SPEED_MOVE), \
			(int)s->pos.y);
	}
	if (s->map[(int)s->pos.x][(int)(s->pos.y - s->dir.y * SPEED_MOVE)] == '0')
	{
		s->pos.y = s->pos.y - s->dir.y * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y - \
		s->dir.y * SPEED_MOVE)], "1567"))
			s->touch_wall.h = DOWN;
		else if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y - \
		s->dir.y * SPEED_MOVE)], "34"))
			ft_touch_sp(s, (int)s->pos.x, (int)(s->pos.y - \
				s->dir.y * SPEED_MOVE));
	}
	ft_touch_wall(s);
}

void	ft_move_left(t_scene *s)
{
	if (s->map[(int)(s->pos.x + s->plane.x * SPEED_MOVE)] \
	[(int)s->pos.y] == '0')
	{
		s->pos.x = s->pos.x + s->plane.x * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)(s->pos.x + s->plane.x * SPEED_MOVE)] \
		[(int)s->pos.y], "1567"))
			s->touch_wall.w = LEFT;
		else if (ft_in_charset(s->map[(int)(s->pos.x + s->plane.x * \
		SPEED_MOVE)][(int)s->pos.y], "34"))
			ft_touch_sp(s, (int)(s->pos.x + s->plane.x * SPEED_MOVE), \
			(int)s->pos.y);
	}
	if (s->map[(int)s->pos.x][(int)(s->pos.y + s->plane.y * \
	SPEED_MOVE)] == '0')
	{
		s->pos.y = s->pos.y + s->plane.y * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y + \
		s->plane.y * SPEED_MOVE)], "1567"))
			s->touch_wall.h = LEFT;
		else if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y + \
		s->plane.y * SPEED_MOVE)], "34"))
			ft_touch_sp(s, (int)s->pos.x, (int)(s->pos.y + s->plane.y * \
			SPEED_MOVE));
	}
	ft_touch_wall(s);
}

void	ft_move_right(t_scene *s)
{
	if (s->map[(int)(s->pos.x - s->plane.x * SPEED_MOVE)] \
	[(int)s->pos.y] == '0')
	{
		s->pos.x = s->pos.x - s->plane.x * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)(s->pos.x - s->plane.x * SPEED_MOVE)] \
		[(int)s->pos.y], "1567"))
			s->touch_wall.w = RIGHT;
		else if (ft_in_charset(s->map[(int)(s->pos.x - s->plane.x * \
				SPEED_MOVE)][(int)s->pos.y], "34"))
			ft_touch_sp(s, (int)(s->pos.x - s->plane.x * SPEED_MOVE), \
				(int)s->pos.y);
	}
	if (s->map[(int)s->pos.x][(int)(s->pos.y - s->plane.y * \
	SPEED_MOVE)] == '0')
	{
		s->pos.y = s->pos.y - s->plane.y * SPEED_MOVE;
		if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y - \
		s->plane.y * SPEED_MOVE)], "1567"))
			s->touch_wall.h = RIGHT;
		if (ft_in_charset(s->map[(int)s->pos.x][(int)(s->pos.y - \
		s->plane.y * SPEED_MOVE)], "34"))
			ft_touch_sp(s, (int)s->pos.x, (int)(s->pos.y - s->plane.y * \
				SPEED_MOVE));
	}
	ft_touch_wall(s);
}
