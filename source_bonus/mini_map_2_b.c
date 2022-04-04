/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_2_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:46:13 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 22:05:58 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_print_items(t_scene *scene, int x, int y)
{
	if (scene->map[y][x] == '1' || scene->map[y][x] == '5')
		ft_square(scene, x, y, WHITE);
	else if (scene->map[y][x] == '6')
		ft_square(scene, x, y, OLIVE);
	else if (scene->map[y][x] == '7')
		ft_square(scene, x, y, GREEN);
	else if (scene->map[y][x] == '2')
		ft_square(scene, x, y, BLUE);
	else if (scene->map[y][x] == '3')
		ft_square(scene, x, y, RED);
	else if (scene->map[y][x] == '4')
		ft_square(scene, x, y, YELLOW);
}
