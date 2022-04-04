/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:29 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 18:56:05 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_set_draw_start_end(t_scene *s)
{
	int	draw_height;

	if (s->dda->side % 2 == 0)
		s->dda->perpwalldist[s->dda->line] = (s->dda->coord.h - s->pos.x + \
		(1 - s->dda->step.h) / 2.) / s->dda->ray_dir.x;
	else
		s->dda->perpwalldist[s->dda->line] = (s->dda->coord.w - s->pos.y + \
		(1 - s->dda->step.w) / 2.) / s->dda->ray_dir.y;
	s->dda->line_height = (s->res.h / s->dda->perpwalldist[s->dda->line]);
	if (s->dda->line_height > s->res.h)
		draw_height = s->res.h;
	else
		draw_height = s->dda->line_height;
	s->dda->draw.h = -draw_height / 2 + s->res.h / 2;
	if (s->dda->draw.h < 0)
		s->dda->draw.h = 0;
	s->dda->draw.w = draw_height / 2 + s->res.h / 2;
	if (s->dda->draw.w >= s->res.h)
		s->dda->draw.w = s->res.h - 1;
}

void	ft_draw_v_line(char *data, t_draw draw, t_scene *scene)
{
	while (draw.length-- > 0)
	{
		if (scene->dark > 0)
			ft_put_pixel_tch(data, draw, draw.color, scene);
		else
			ft_put_pixel(data, draw, draw.color, scene);
		draw.start.h++;
	}
}

void	ft_drw_txt_line_2(t_scene *s, t_texdata *tx)
{
	double	wall_x;

	tx->tex_size = s->textures[s->dda->side]->size;
	if (s->dda->side % 2 == 0)
		wall_x = s->pos.y + s->dda->perpwalldist[s->dda->line] * \
			s->dda->ray_dir.y;
	else
		wall_x = s->pos.x + s->dda->perpwalldist[s->dda->line] * \
			s->dda->ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	tx->texx = wall_x * (double)tx->tex_size.w;
	if (s->dda->side % 2 == 0 && s->dda->ray_dir.x > 0)
		tx->texx = tx->tex_size.w - tx->texx - 1;
	if (s->dda->side % 2 == 1 && s->dda->ray_dir.y < 0)
		tx->texx = tx->tex_size.w - tx->texx - 1;
	tx->step = (double)tx->tex_size.h / s->dda->line_height;
	tx->texpos = (s->dda->draw.h - s->res.h / 2 + s->dda->line_height / 2) * \
				tx->step;
	if (s->dda->line_height < s->res.h)
		tx->length = s->dda->line_height;
	else
		tx->length = s->res.h;
}

void	ft_draw_texture_line(char *data, t_int pos, t_scene *s)
{
	t_texdata	tx;
	t_draw		draw;

	ft_drw_txt_line_2(s, &tx);
	while (tx.length-- > 0)
	{
		tx.texy = (int)tx.texpos & (tx.tex_size.h - 1);
		tx.texpos = tx.texpos + tx.step;
		draw.start = pos;
		draw.length = tx.tex_size.h * tx.texy + tx.texx;
		if (s->dark > 0)
			ft_put_texture_tch(data, draw, s->textures[s->dda->side]->data, s);
		else
			ft_put_texture(data, draw, s->textures[s->dda->side]->data, s);
		pos.h++;
	}
}

void	ft_draw_wall(char *data, t_scene *s)
{
	t_int	pixel;
	t_draw	draw;

	pixel.w = s->res.w - s->dda->line - 1;
	pixel.h = 0;
	draw.start = pixel;
	draw.length = s->dda->draw.h;
	ft_draw_v_line_dark(data, draw, s);
	pixel.h = pixel.h + s->dda->draw.h;
	ft_draw_texture_line(data, pixel, s);
	if (s->is_wall)
		ft_draw_texture_line_add(data, pixel, s);
	pixel.h = pixel.h + s->dda->draw.w - s->dda->draw.h;
	draw.start = pixel;
	draw.length = s->res.h - s->dda->draw.w;
	ft_draw_v_line_dark_2(data, draw, s);
}
