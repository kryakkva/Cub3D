/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekharjo <sekharjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:14:27 by apaege            #+#    #+#             */
/*   Updated: 2022/04/05 12:38:52 by sekharjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_rgb	*ft_int_to_rgb(int r, int g, int b)
{
	t_rgb	*rgb;

	rgb = ft_calloc(sizeof(t_rgb), 1);
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

static t_rgb	*ft_str_to_rgb(char *str)
{
	char	**data;
	t_rgb	*res;
	int		r;
	int		g;
	int		b;

	if (str[ft_strlen(str) - 1] == ',')
		return (NULL);
	data = ft_split(str, ',');
	if (ft_mass_len(data) != 3)
	{
		ft_free_array(data);
		return (NULL);
	}
	r = ft_atoi(data[0]);
	g = ft_atoi(data[1]);
	b = ft_atoi(data[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_print_error("RGB value out of range", PARSE_ERROR);
	res = ft_int_to_rgb(r, g, b);
	ft_free_array(data);
	return (res);
}

void	ft_set_color(t_scene *scene, char **data, int code)
{
	if (!code)
	{
		scene->floor = ft_str_to_rgb(data[1]);
		if (!scene->floor)
			ft_print_error("Color must have 3 values in range 0-255",
				PARSE_ERROR);
	}
	else
	{
		scene->ceil = ft_str_to_rgb(data[1]);
		if (!scene->ceil)
			ft_print_error("Color must have 3 values in range 0-255",
				PARSE_ERROR);
	}
}

int	ft_rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

int	ft_str_to_int(char *str)
{
	int		color;
	t_rgb	*rgb;

	rgb = ft_str_to_rgb(str);
	color = ft_rgb_to_int(*rgb);
	free(rgb);
	return (color);
}
