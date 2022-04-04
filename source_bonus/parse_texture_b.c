/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:12:08 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:18:38 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static int	ft_parse_other(t_scene *s, int i)
{
	while (i < NB_TEXTURES - 1)
	{
		if (s->tex[i])
		{
			s->textures[i] = ft_calloc(sizeof(t_img), 1);
			s->textures[i]->img_ptr = mlx_xpm_file_to_image(s->mlx,
					s->tex[i], &(s->textures[i]->size.w), \
					&(s->textures[i]->size.h));
			if (!s->textures[i]->img_ptr)
				ft_print_error("Texture not found 0", MLX_ERROR);
			s->textures[i]->data = mlx_get_data_addr(s->textures[i]->img_ptr,
					&s->textures[i]->bits_per_pixel, &s->textures[i]->size_line,
					&s->textures[i]->endian);
			if (!s->textures[i]->data)
				ft_print_error("Data texture error", MLX_ERROR);
		}
		i++;
	}
	return (i);
}

static void	ft_parse_anim(t_scene *s, int i, int n)
{
	char	*tmp;
	char	*num;
	int		j;

	j = 0;
	while (j < n)
	{
		num = ft_itoa(j);
		if (j == 0)
			tmp = ft_strdup(s->tex[i]);
		else
			tmp = ft_strjoin(s->tex[i], num);
		free(num);
		s->textures[i][j].img_ptr = mlx_xpm_file_to_image(s->mlx,
				tmp, &(s->textures[i]->size.w), \
				&(s->textures[i]->size.h));
		if (!s->textures[i][j].img_ptr)
			ft_print_error("Texture not found 2", MLX_ERROR);
		s->textures[i][j].data = mlx_get_data_addr(s->textures[i][j].img_ptr,
				&s->textures[i][j].bits_per_pixel, &s->textures[i][j].size_line,
				&s->textures[i][j].endian);
		if (!s->textures[i][j++].data)
			ft_print_error("Data texture error", MLX_ERROR);
		free(tmp);
	}
}

static int	ft_parse_sprite(t_scene *s, int i, int n)
{	
	int	j;

	if (i == NB_TEXTURES - 1)
		j = NB_TEXTURES;
	else
		j = 7;
	while (i < j)
	{
		if (s->tex[i])
		{
			s->textures[i] = ft_calloc(sizeof(t_img), n);
			ft_parse_anim(s, i, n);
		}
		i++;
	}
	return (i);
}

static void	ft_pre_parse_textures(t_scene *s)
{
	if ((s->pars.sp2 && !s->tex[SPRITE2])
		|| (s->pars.sp3 && !s->tex[SPRITE3])
		|| (s->pars.sp4 && !s->tex[SPRITE4])
		|| (s->pars.fl5 && !s->tex[FLAG])
		|| (s->pars.dr6 && !s->tex[DOOR])
		|| (s->pars.ex7 && !s->tex[EXIT]))
		ft_print_error("Texture not found", PARSE_ERROR);
}

void	ft_parse_textures(t_scene *s)
{
	int	i;
	int	j;

	i = -1;
	ft_pre_parse_textures(s);
	while (++i < 4)
	{
		if (s->tex[i])
		{
			s->textures[i] = ft_calloc(sizeof(t_img), 1);
			s->textures[i]->img_ptr = mlx_xpm_file_to_image(s->mlx,
					s->tex[i], &(s->textures[i]->size.w), \
					&(s->textures[i]->size.h));
			if (!s->textures[i]->img_ptr)
				ft_print_error("Texture not found 0", MLX_ERROR);
			s->textures[i]->data = mlx_get_data_addr(s->textures[i]->img_ptr,
					&s->textures[i]->bits_per_pixel, &s->textures[i]->size_line,
					&s->textures[i]->endian);
			if (!s->textures[i]->data)
				ft_print_error("Data texture error", MLX_ERROR);
		}
	}
	i = ft_parse_sprite(s, i, 5);
	i = ft_parse_other(s, i);
	i = ft_parse_sprite(s, i, 2);
}
