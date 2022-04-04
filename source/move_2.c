/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:28:41 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 17:57:57 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_turn_left(t_scene *scene)
{
	ft_offset(&scene->dir, THETA);
	ft_offset(&scene->plane, THETA);
	ft_refresh(scene);
}

void	ft_turn_right(t_scene *scene)
{
	ft_offset(&scene->dir, -THETA);
	ft_offset(&scene->plane, -THETA);
	ft_refresh(scene);
}
