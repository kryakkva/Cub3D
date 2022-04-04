/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:57:18 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 21:11:17 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_draw_line(t_scene *scene, t_draw draw)
{
	int			x_max;
	int			y_max;
	int			i;
	t_double	pos;

	x_max = 20 + ft_strlen(scene->map[(int)scene->pos.x]) * \
			scene->res.h / 100;
	y_max = 30 + scene->size.h * scene->res.h / 100;
	pos.x = draw.start.h;
	pos.y = draw.start.w;
	i = scene->res.h / 25;
	while (i--)
	{
		if (scene->dark > 0)
			ft_put_pixel_tch(scene->img->data, draw, draw.color, scene);
		else
			ft_put_pixel(scene->img->data, draw, draw.color, scene);
		pos.x = pos.x + draw.end.y;
		pos.y = pos.y + draw.end.x;
		draw.start.h = pos.x;
		draw.start.w = pos.y;
	}
}

static void	ft_draw_square(t_scene *scn, t_draw draw)
{
	int	i;

	i = 0;
	while (i < draw.length)
	{
		ft_draw_v_line(scn->img->data, draw, scn);
		draw.start.w++;
		i++;
	}
}

void	ft_draw_minimap_position(t_scene *scn)
{
	t_draw	draw;

	draw.start.w = 20 + scn->pos.y * scn->res.h / scn->coef - scn->res.h / 400;
	draw.start.h = 30 + scn->pos.x * scn->res.h / scn->coef - scn->res.h / 400;
	draw.length = scn->res.h / 200;
	draw.color = AQUA;
	ft_draw_square(scn, draw);
	draw.start.w = draw.start.w + scn->res.h / 400;
	draw.start.h = draw.start.h + scn->res.h / 400;
	draw.end.x = scn->dir.y / 6;
	draw.end.y = scn->dir.x / 6;
	draw.color = AQUA;
	ft_draw_line(scn, draw);
}

void	ft_square(t_scene *scene, int x, int y, int color)
{
	t_draw	draw;

	draw.start.w = 20 + x * scene->res.h / scene->coef;
	draw.start.h = 30 + y * scene->res.h / scene->coef;
	draw.length = scene->res.h / 200;
	draw.color = color;
	ft_draw_square(scene, draw);
}

void	ft_draw_minimap(t_scene *scene)
{
	int		x;
	int		y;
	int		len;

	y = 0;
	while (y < scene->size.h)
	{
		x = 0;
		len = ft_strlen(scene->map[y]);
		while (x < len)
		{
			ft_print_items(scene, x, y);
			x++;
		}
		y++;
	}
}
