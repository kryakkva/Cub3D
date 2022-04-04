/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:08:01 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 12:49:11 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_calculate_dda(t_dda *dda, t_scene *scene, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	dda->ray_dir.x = scene->dir.x + scene->plane.x * camera_x;
	dda->ray_dir.y = scene->dir.y + scene->plane.y * camera_x;
	dda->coord.h = (int)scene->pos.x;
	dda->coord.w = (int)scene->pos.y;
	dda->delta_dist.x = fabs(1 / dda->ray_dir.x);
	dda->delta_dist.y = fabs(1 / dda->ray_dir.y);
}

void	ft_set_side_dist(t_dda *dda, t_scene *scn)
{
	if (dda->ray_dir.x < 0)
	{
		dda->step.h = -1;
		dda->side_dist.x = (scn->pos.x - dda->coord.h) * dda->delta_dist.x;
	}
	else
	{
		dda->step.h = 1;
		dda->side_dist.x = (dda->coord.h + 1.0 - scn->pos.x) * \
			dda->delta_dist.x;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->step.w = -1;
		dda->side_dist.y = (scn->pos.y - dda->coord.w) * dda->delta_dist.y;
	}
	else
	{
		dda->step.w = 1;
		dda->side_dist.y = (dda->coord.w + 1.0 - scn->pos.y) * \
			dda->delta_dist.y;
	}
}

int	ft_check_hit(t_dda *dda, t_scene *scene)
{
	if (dda->coord.h < 0 || dda->coord.h == scene->size.h
		|| dda->coord.w < 0 || dda->coord.w == scene->size.w)
		return (1);
	else if (scene->map[dda->coord.h][dda->coord.w] != '0')
		return (1);
	return (0);
}

void	ft_perform_dda(t_dda *dda, t_scene *scene)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x = dda->side_dist.x + dda->delta_dist.x;
			dda->coord.h = dda->coord.h + dda->step.h;
			if (dda->ray_dir.x > 0)
				dda->side = 0;
			else
				dda->side = 2;
		}
		else
		{
			dda->side_dist.y = dda->side_dist.y + dda->delta_dist.y;
			dda->coord.w = dda->coord.w + dda->step.w;
			if (dda->ray_dir.y > 0)
				dda->side = 1;
			else
				dda->side = 3;
		}
		hit = ft_check_hit(dda, scene);
	}
}

void	ft_draw_image(t_scene *scene)
{
	t_dda	*dda;

	dda = ft_calloc(sizeof(t_dda), 1);
	dda->line = 0;
	while (dda->line <= WIDTH)
	{
		ft_calculate_dda(dda, scene, dda->line);
		ft_set_side_dist(dda, scene);
		ft_perform_dda(dda, scene);
		ft_set_draw_start_end(dda, scene);
		ft_draw_wall(scene->img->data, dda, scene);
		dda->line++;
	}
	free(dda);
}
