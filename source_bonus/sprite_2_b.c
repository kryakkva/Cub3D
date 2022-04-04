/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:08:10 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:47:56 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_sort_sprite(t_scene *s, int sprite_order[], double sprite_dist[])
{
	int	i;
	int	fl;

	fl = 1;
	while (fl)
	{
		i = 0;
		fl = 0;
		while (i < s->dda->spr_ind - 1)
		{
			if (sprite_dist[i] < sprite_dist[i + 1])
			{
				ft_swap_dbl(&sprite_dist[i], &sprite_dist[i + 1]);
				ft_swap(&sprite_order[i], &sprite_order[i + 1]);
				ft_swap_spr(&s->dda->sprite_pos[i], \
					&s->dda->sprite_pos[i + 1]);
				ft_swap_int(&s->dda->sprite_nbr[i], \
					&s->dda->sprite_nbr[i + 1]);
				fl = 1;
			}
			i++;
		}
	}
}

void	ft_get_sprite(t_scene *s, int sprite_order[])
{
	int		i;
	double	*sprite_dist;

	i = 0;
	sprite_dist = ft_calloc(sizeof(double), s->dda->spr_ind);
	while (i < s->dda->spr_ind)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((s->pos.x - s->dda->sprite_pos[i].h) * (s->pos.x - \
			s->dda->sprite_pos[i].h) + (s->pos.y - s->dda->sprite_pos[i].w) * \
			(s->pos.y - s->dda->sprite_pos[i].w));
		i++;
	}
	ft_sort_sprite(s, sprite_order, sprite_dist);
	free(sprite_dist);
}

void	ft_print_sprite(t_scene *s, t_sprite *sp)
{
	int		y;
	int		d;
	int		tex_y;
	t_draw	draw;

	y = sp->drawstart_y;
	while (y <= sp->drawend_y)
	{
		d = y * 256 - s->res.h * 128 + sp->sprite_height * 128;
		tex_y = ((d * s->textures[s->dda->sprite_nbr[sp->i]]->size.h) / \
			sp->sprite_height) / 256;
		draw.start.w = s->res.w - sp->line - 1;
		draw.start.h = y;
		draw.length = s->textures[s->dda->sprite_nbr[sp->i]]->size.w * \
			tex_y + sp->tex_x;
		if (s->dark > 0)
			ft_put_txtr_fr_tch(s->img->data, draw, \
				s->textures[s->dda->sprite_nbr[sp->i]]->data, s);
		else
			ft_put_texture_fr(s->img->data, draw, s->textures \
				[s->dda->sprite_nbr[sp->i]][s->itter / 700].data, s);
		y++;
	}
}
