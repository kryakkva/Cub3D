/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_add_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:25 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:28:14 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_set_color_coeff(t_scene *scene, t_rgb *color)
{
	scene->color_k.r = color->r / (1.1 * SMOKE);
	scene->color_k.g = color->g / (1.1 * SMOKE);
	scene->color_k.b = color->b / (1.1 * SMOKE);
}

void	ft_set_color_new(t_scene *scene, t_rgb *color, int k)
{
	ft_set_color_coeff(scene, color);
	scene->color_new.r = color->r - k * scene->color_k.r;
	scene->color_new.g = color->g - k * scene->color_k.g;
	scene->color_new.b = color->b - k * scene->color_k.b;
}

void	ft_draw_v_line_dark(char *data, t_draw draw, t_scene *s)
{
	s->dark_k = 0;
	while (draw.length-- > 0)
	{
		if (draw.start.h >= (s->res.h * s->dark_k) / (SMOKE * 2)
			&& draw.start.h <= (s->res.h * (s->dark_k + 1)) / (SMOKE * 2))
		{
			ft_set_color_new(s, s->ceil, s->dark_k);
			draw.color = ft_rgb_to_int(s->color_new);
			s->dark_k++;
		}
		if (s->dark > 0)
			ft_put_pixel_tch(data, draw, draw.color, s);
		else
			ft_put_pixel(data, draw, draw.color, s);
		draw.start.h++;
	}
}

void	ft_draw_v_line_dark_2(char *data, t_draw draw, t_scene *s)
{
	while (draw.length-- > 0)
	{
		ft_set_color_new(s, s->floor, s->dark_k);
		draw.color = ft_rgb_to_int(s->color_new);
		if (draw.start.h >= (s->res.h - ((s->res.h * s->dark_k) / (SMOKE * 2)))
			&& draw.start.h <= (s->res.h - ((s->res.h * (s->dark_k - 1)) / \
			(SMOKE * 2))))
		{
			ft_set_color_new(s, s->floor, s->dark_k);
			draw.color = ft_rgb_to_int(s->color_new);
			s->dark_k--;
		}
		if (s->dark > 0)
			ft_put_pixel_tch(data, draw, draw.color, s);
		else
			ft_put_pixel(data, draw, draw.color, s);
		draw.start.h++;
	}
}

void	ft_one_int_to_rgb(t_scene *s, int color)
{
	s->color_new.r = color >> 16 & 0x000000FF;
	s->color_new.g = color >> 8 & 0x000000FF;
	s->color_new.b = color & 0x000000FF;
}
