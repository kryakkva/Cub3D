/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_touch_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:48:52 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:24:09 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_put_pixel_tch(char *data, t_draw draw, int color, t_scene *s)
{
	int	(*tab);

	tab = (void *)data;
	color = (color >> 2) & 4144959;
	tab[draw.start.h * s->res.w + draw.start.w] = color;
}

void	ft_put_texture_tch(char *data, t_draw draw, char *texdata, t_scene *s)
{
	int	(*tab);
	int	(*tabtexture);
	int	color;

	tab = (void *)data;
	tabtexture = (void *)texdata;
	color = tabtexture[draw.length];
	color = (color >> 2) & 4144959;
	tab[draw.start.h * s->res.w + draw.start.w] = color;
}

void	ft_put_txtr_fr_tch(char *data, t_draw draw, char *texdata, t_scene *s)
{
	int	(*tab);
	int	(*tabtexture);
	int	color;

	tab = (void *)data;
	tabtexture = (void *)texdata;
	color = tabtexture[draw.length];
	color = (color >> 2) & 4144959;
	if ((tabtexture[draw.length] & 16777215) != 0)
		tab[draw.start.h * s->res.w + draw.start.w] = color;
}
