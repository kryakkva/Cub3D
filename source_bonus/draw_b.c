/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:08:01 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:04:05 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_calculate_dda(t_scene *scene, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)scene->res.w - 1;
	scene->dda->ray_dir.x = scene->dir.x + scene->plane.x * camera_x;
	scene->dda->ray_dir.y = scene->dir.y + scene->plane.y * camera_x;
	scene->dda->coord.h = (int)scene->pos.x;
	scene->dda->coord.w = (int)scene->pos.y;
	scene->dda->delta_dist.x = fabs(1 / scene->dda->ray_dir.x);
	scene->dda->delta_dist.y = fabs(1 / scene->dda->ray_dir.y);
}

void	ft_set_side_dist(t_scene *s)
{
	if (s->dda->ray_dir.x < 0)
	{
		s->dda->step.h = -1;
		s->dda->side_dist.x = (s->pos.x - s->dda->coord.h) * \
			s->dda->delta_dist.x;
	}
	else
	{
		s->dda->step.h = 1;
		s->dda->side_dist.x = (s->dda->coord.h + 1.0 - s->pos.x) * \
			s->dda->delta_dist.x;
	}
	if (s->dda->ray_dir.y < 0)
	{
		s->dda->step.w = -1;
		s->dda->side_dist.y = (s->pos.y - s->dda->coord.w) * \
			s->dda->delta_dist.y;
	}
	else
	{
		s->dda->step.w = 1;
		s->dda->side_dist.y = (s->dda->coord.w + 1.0 - s->pos.y) * \
			s->dda->delta_dist.y;
	}
}

int	ft_check_hit(t_scene *s)
{
	if (s->map[s->dda->coord.h][s->dda->coord.w] == '1')
	{
		s->is_wall = 0;
		return (1);
	}
	else if (s->map[s->dda->coord.h][s->dda->coord.w] == '5'
		|| s->map[s->dda->coord.h][s->dda->coord.w] == '6'
		|| s->map[s->dda->coord.h][s->dda->coord.w] == '7')
	{
		s->is_wall = s->map[s->dda->coord.h][s->dda->coord.w] - 46;
		return (1);
	}
	else
		ft_set_sprite_index(s);
	return (0);
}

void	ft_perform_dda(t_scene *s)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (s->dda->side_dist.x < s->dda->side_dist.y)
		{
			s->dda->side_dist.x = s->dda->side_dist.x + s->dda->delta_dist.x;
			s->dda->coord.h = s->dda->coord.h + s->dda->step.h;
			if (s->dda->ray_dir.x > 0)
				s->dda->side = 0;
			else
				s->dda->side = 2;
		}
		else
		{
			s->dda->side_dist.y = s->dda->side_dist.y + s->dda->delta_dist.y;
			s->dda->coord.w = s->dda->coord.w + s->dda->step.w;
			if (s->dda->ray_dir.y > 0)
				s->dda->side = 1;
			else
				s->dda->side = 3;
		}
		hit = ft_check_hit(s);
	}
}

void	ft_draw_image(t_scene *scene)
{
	scene->dda = ft_calloc(sizeof(*(scene->dda)), 1);
	scene->dda->line = 0;
	scene->dda->spr_ind = 0;
	scene->dda->sprite_pos = ft_calloc(sizeof(*scene->dda->sprite_pos), \
		scene->nbr_sprite);
	while (scene->dda->line < scene->res.w)
	{
		ft_calculate_dda(scene, scene->dda->line);
		ft_set_side_dist(scene);
		ft_perform_dda(scene);
		ft_set_draw_start_end(scene);
		ft_draw_wall(scene->img->data, scene);
		ft_draw_minimap_position(scene);
		scene->dda->line++;
	}
	ft_draw_minimap(scene);
}
