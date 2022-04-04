/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:14:35 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:24:48 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_put_pixel(char *data, t_draw draw, int color, t_scene *s)
{
	int	(*tab);

	(void)color;
	tab = (void *)data;
	tab[draw.start.h * s->res.w + draw.start.w] = color;
}

void	ft_put_texture(char *data, t_draw draw, char *texdata, t_scene *s)
{
	int	(*tab);
	int	(*tabtexture);
	int	color;

	tab = (void *)data;
	tabtexture = (void *)texdata;
	color = tabtexture[draw.length];
	ft_one_int_to_rgb(s, color);
	ft_set_color_new(s, &s->color_new, s->dark_k);
	color = ft_rgb_to_int(s->color_new);
	tab[draw.start.h * s->res.w + draw.start.w] = color;
}

void	ft_put_texture_fr(char *data, t_draw draw, char *texdata, t_scene *s)
{
	int	(*tab);
	int	(*tabtexture);
	int	color;

	tab = (void *)data;
	tabtexture = (void *)texdata;
	color = tabtexture[draw.length];
	ft_one_int_to_rgb(s, color);
	ft_set_color_new(s, &s->color_new, s->dark_k);
	color = ft_rgb_to_int(s->color_new);
	if ((color & 16777215) != 0)
		tab[draw.start.h * s->res.w + draw.start.w] = color;
}
