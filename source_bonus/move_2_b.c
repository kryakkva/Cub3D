/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:28:41 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 15:41:46 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_turn_left(t_scene *scene)
{
	ft_offset(&scene->dir, THETA);
	ft_offset(&scene->plane, THETA);
	scene->dark--;
	ft_refresh(scene);
}

void	ft_turn_right(t_scene *scene)
{
	ft_offset(&scene->dir, -THETA);
	ft_offset(&scene->plane, -THETA);
	scene->dark--;
	ft_refresh(scene);
}
