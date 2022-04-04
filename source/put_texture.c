/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:14:35 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 18:04:15 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_pixel(char *data, t_draw draw, int color)
{
	int	(*tab)[WIDTH][1];

	tab = (void *)data;
	*tab[draw.start.h][draw.start.w] = color;
}

void	ft_put_texture(char *data, t_draw draw, char *texdata)
{
	int	(*tab);
	int	(*tabtexture);

	tab = (void *)data;
	tabtexture = (void *)texdata;
	tab[draw.start.h * WIDTH + draw.start.w] = tabtexture[draw.length];
}
