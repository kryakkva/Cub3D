/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekharjo <sekharjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:01:25 by apaege            #+#    #+#             */
/*   Updated: 2022/04/04 16:55:56 by sekharjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_sprite_1(t_scene *s, t_sprite *sp, int sprite_order[])
{
	double	spr_x;
	double	spr_y;
	double	inv;
	double	transf_x;

	spr_x = s->dda->sprite_pos[sprite_order[sp->i]].h + 0.5 - s->pos.x;
	spr_y = s->dda->sprite_pos[sprite_order[sp->i]].w + 0.5 - s->pos.y;
	inv = 1.0 / (s->plane.x * s->dir.y - s->dir.x * s->plane.y);
	transf_x = inv * (s->dir.y * spr_x - s->dir.x * spr_y);
	sp->transform_y = inv * (s->plane.x * spr_y - s->plane.y * spr_x);
	sp->spritescrx = (int)((s->res.w / 2) * (1 + transf_x / sp->transform_y));
	sp->sprite_height = abs((int)(s->res.h / sp->transform_y));
	sp->drawstart_y = s->res.h / 2 - sp->sprite_height / 2;
	if (sp->drawstart_y < 0)
		sp->drawstart_y = 0;
	sp->drawend_y = sp->sprite_height / 2 + s->res.h / 2 - 1;
	if (sp->drawend_y >= s->res.h)
		sp->drawend_y = s->res.h - 1;
	sp->sprite_width = abs((int)(s->res.h / sp->transform_y));
	sp->drawstart_x = sp->spritescrx - sp->sprite_width / 2;
	if (sp->drawstart_x < 0)
		sp->drawstart_x = 0;
	sp->drawend_x = sp->sprite_width / 2 + sp->spritescrx - 1;
	if (sp->drawend_x >= s->res.w)
		sp->drawend_x = s->res.w - 1;
}

static void	ft_sprite_2(t_scene *s, t_sprite *sp)
{
	sp->line = sp->drawstart_x;
	while (sp->line <= sp->drawend_x)
	{
		sp->tex_x = (int)(256 * (sp->line - (sp->spritescrx - \
			sp->sprite_width / 2)) * \
			s->textures[s->dda->sprite_nbr[sp->i]]->size.w / \
			sp->sprite_width) / 256;
		if (sp->tex_x < 0)
			sp->tex_x = 0;
		if (sp->transform_y >= 0 && sp->line > 0 && sp->line < s->res.w
			&& sp->transform_y < s->dda->perpwalldist[sp->line])
			ft_print_sprite(s, sp);
		sp->line++;
	}
}

int	ft_create_sprite(t_scene *s)
{
	int			*sprite_order;
	t_sprite	sp;

	sprite_order = ft_calloc(sizeof(int), s->dda->spr_ind);
	ft_get_sprite(s, sprite_order);
	sp.i = 0;
	while (sp.i < s->dda->spr_ind)
	{
		s->dark_k = sqrtf((s->pos.x - s->dda->sprite_pos[sp.i].h) * (s->pos.x - \
		s->dda->sprite_pos[sp.i].h) + (s->pos.y - \
		s->dda->sprite_pos[sp.i].w) * (s->pos.y - \
		s->dda->sprite_pos[sp.i].w)) * 1.9;
		ft_sprite_1(s, &sp, sprite_order);
		ft_sprite_2(s, &sp);
		sp.i++;
	}
	free(sprite_order);
	return (0);
}

int	ft_is_sprite(t_scene *s)
{
	int	i;

	i = 0;
	while (i < s->dda->spr_ind)
	{
		if (s->dda->sprite_pos[i].h == s->dda->coord.h
			&& s->dda->sprite_pos[i].w == s->dda->coord.w)
			return (1);
		i++;
	}
	return (0);
}

void	ft_set_sprite_index(t_scene *s)
{
	if ((s->map[s->dda->coord.h][s->dda->coord.w] == '2'
		|| s->map[s->dda->coord.h][s->dda->coord.w] == '3'
			|| s->map[s->dda->coord.h][s->dda->coord.w] == '4')
			&& !ft_is_sprite(s))
	{
		s->dda->sprite_pos[s->dda->spr_ind].h = s->dda->coord.h;
		s->dda->sprite_pos[s->dda->spr_ind].w = s->dda->coord.w;
		s->dda->sprite_nbr[s->dda->spr_ind] = \
			s->map[s->dda->coord.h][s->dda->coord.w] - 46;
		s->dda->spr_ind++;
	}
}
