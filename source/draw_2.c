/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:29 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 12:49:00 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_draw_start_end(t_dda *dda, t_scene *scene)
{
	int	draw_height;

	if (dda->side % 2 == 0)
		dda->perpwalldist[dda->line] = (dda->coord.h - scene->pos.x + \
		(1 - dda->step.h) / 2.) / dda->ray_dir.x;
	else
		dda->perpwalldist[dda->line] = (dda->coord.w - scene->pos.y + \
		(1 - dda->step.w) / 2.) / dda->ray_dir.y;
	dda->line_height = (HEIGHT / dda->perpwalldist[dda->line]);
	if (dda->line_height > HEIGHT)
		draw_height = HEIGHT;
	else
		draw_height = dda->line_height;
	dda->draw.h = -draw_height / 2 + HEIGHT / 2;
	if (dda->draw.h < 0)
		dda->draw.h = 0;
	dda->draw.w = draw_height / 2 + HEIGHT / 2;
	if (dda->draw.w >= HEIGHT)
		dda->draw.w = HEIGHT - 1;
}

void	ft_draw_v_line(char *data, t_draw draw)
{
	while (draw.length-- > 0)
	{
		ft_put_pixel(data, draw, draw.color);
		draw.start.h++;
	}
}

void	ft_drw_txt_line_2(t_dda *dda, t_scene *scene, t_texdata *tx)
{
	double	wall_x;

	tx->tex_size = scene->textures[dda->side]->size;
	if (dda->side % 2 == 0)
		wall_x = scene->pos.y + dda->perpwalldist[dda->line] * dda->ray_dir.y;
	else
		wall_x = scene->pos.x + dda->perpwalldist[dda->line] * dda->ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	tx->texx = wall_x * (double)tx->tex_size.w;
	if (dda->side % 2 == 0 && dda->ray_dir.x > 0)
		tx->texx = tx->tex_size.w - tx->texx - 1;
	if (dda->side % 2 == 1 && dda->ray_dir.y < 0)
		tx->texx = tx->tex_size.w - tx->texx - 1;
	tx->step = (double)tx->tex_size.h / dda->line_height;
	tx->texpos = (dda->draw.h - HEIGHT / 2 + dda->line_height / 2) * tx->step;
	if (dda->line_height < HEIGHT)
		tx->length = dda->line_height;
	else
		tx->length = HEIGHT;
}

void	ft_draw_texture_line(char *data, t_int pos, t_dda *dda, t_scene *scene)
{
	t_texdata	tx;
	t_draw		draw;

	ft_drw_txt_line_2(dda, scene, &tx);
	while (tx.length-- > 0)
	{
		tx.texy = (int)tx.texpos & (tx.tex_size.h - 1);
		tx.texpos = tx.texpos + tx.step;
		draw.start = pos;
		draw.length = tx.tex_size.w * tx.texy + tx.texx;
		ft_put_texture(data, draw, scene->textures[dda->side]->data);
		pos.h++;
	}
}

void	ft_draw_wall(char *data, t_dda *dda, t_scene *scene)
{
	t_int	pixel;
	t_draw	draw;

	pixel.w = WIDTH - dda->line;
	pixel.h = 0;
	draw.start = pixel;
	draw.length = dda->draw.h;
	draw.color = ft_rgb_to_int(*scene->ceil);
	ft_draw_v_line(data, draw);
	pixel.h = pixel.h + dda->draw.h;
	ft_draw_texture_line(data, pixel, dda, scene);
	pixel.h = pixel.h + dda->draw.w - dda->draw.h;
	draw.start = pixel;
	draw.length = HEIGHT - dda->draw.w;
	draw.color = ft_rgb_to_int(*scene->floor);
	ft_draw_v_line(data, draw);
}
