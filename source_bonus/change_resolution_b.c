/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_resolution_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:29:28 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 18:51:53 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_change_res_2(char *line, t_scene *scene)
{
	if (!ft_strcmp(line, "RES3"))
	{
		scene->res.w = 2560;
		scene->res.h = 1440;
		scene->coef = 240;
		free(line);
	}
	else if (!ft_strcmp(line, "\0"))
	{
		scene->res.w = 800;
		scene->res.h = 600;
		scene->coef = 200;
		free(line);
	}
	else
		ft_print_error("You enter incorrect value", RES_ERROR);
}

static void	ft_change_res(char *line, t_scene *scene)
{
	if (!ft_strcmp(line, "RES1"))
	{
		scene->res.w = 1440;
		scene->res.h = 900;
		scene->coef = 230;
		free(line);
	}
	else if (!ft_strcmp(line, "RES2"))
	{
		scene->res.w = 1920;
		scene->res.h = 1080;
		scene->coef = 220;
		free(line);
	}
	else
		ft_change_res_2(line, scene);
}

void	ft_change_resolution(t_scene *scene)
{
	char	*line;

	ft_putendl_fd("Enter RES1 to install resolution 1440x900", 1);
	ft_putendl_fd("Enter RES2 to install resolution 1920x1080", 1);
	ft_putendl_fd("Enter RES3 to install resolution 2560x1440", 1);
	get_next_line(0, &line);
	ft_change_res(line, scene);
}
