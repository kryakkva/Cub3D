/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 01:00:29 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:02:01 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_drw_txt_line_2_add(t_scene *s, t_texdata *tx)
{
	double	wall_x;

	tx->tex_size = s->textures[s->is_wall]->size;
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

static void	ft_draw_text_line_prn(char *data, t_int pos, t_scene *s, t_draw dr)
{
	if (s->dark > 0)
	{
		if (s->is_wall == 9 && !s->pars.sp4)
			ft_put_txtr_fr_tch(data, dr, \
				s->textures[s->is_wall][1].data, s);
		else
			ft_put_txtr_fr_tch(data, dr, \
			s->textures[s->is_wall]->data, s);
	}
	else
	{
		if (s->is_wall == 9 && !s->pars.sp4)
			ft_put_texture_fr(data, dr, \
				s->textures[s->is_wall][1].data, s);
		else
			ft_put_texture_fr(data, dr, \
				s->textures[s->is_wall]->data, s);
	}
}

void	ft_draw_texture_line_add(char *data, t_int pos, t_scene *s)
{
	t_texdata	tx;
	t_draw		draw;

	ft_drw_txt_line_2_add(s, &tx);
	while (tx.length-- > 0)
	{
		tx.texy = (int)tx.texpos & (tx.tex_size.h - 1);
		tx.texpos = tx.texpos + tx.step;
		draw.start = pos;
		draw.length = tx.tex_size.w * tx.texy + tx.texx;
		ft_draw_text_line_prn(data, pos, s, draw);
		pos.h++;
	}
}
