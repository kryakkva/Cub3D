/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr_2_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:01:03 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:13:46 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static int	ft_set_all_bonus_2(t_scene *scene, char **data)
{
	if ((data[0][0] == '1') || ((scene->tex[FLAG]) && (data[0][0] == '5'))
		|| ((scene->tex[EXIT]) && (data[0][0] == '7')))
	{
		ft_free_array(data);
		return (1);
	}
	else
		ft_print_error("Invalid line parsing", PARSE_ERROR);
	return (0);
}

static int	ft_set_all_bonus(t_scene *scene, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (ft_check_line(data, "SP2") && !scene->tex[SPRITE2])
		scene->tex[SPRITE2] = ft_strdup(data[1]);
	else if (ft_check_line(data, "SP3") && !scene->tex[SPRITE3])
		scene->tex[SPRITE3] = ft_strdup(data[1]);
	else if (ft_check_line(data, "SP4") && !scene->tex[SPRITE4])
		scene->tex[SPRITE4] = ft_strdup(data[1]);
	else if (ft_check_line(data, "FL5") && !scene->tex[FLAG])
		scene->tex[FLAG] = ft_strdup(data[1]);
	else if (ft_check_line(data, "DR6") && !scene->tex[DOOR])
		scene->tex[DOOR] = ft_strdup(data[1]);
	else if (ft_check_line(data, "EX7") && !scene->tex[EXIT])
		scene->tex[EXIT] = ft_strdup(data[1]);
	else if (ft_set_all_bonus_2(scene, data))
		return (1);
	free(line);
	ft_free_array(data);
	return (0);
}

void	ft_parse_bonus(int fd, t_scene *scn)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (!line[0])
		{
			free(line);
			continue ;
		}
		else if (ft_only_space_lines(line))
			ft_print_error("Invalid line parsing", PARSE_ERROR);
		if (ft_set_all_bonus(scn, line))
			break ;
		scn->nb_textures++;
	}
	ft_parse_map(scn, fd, line);
}

void	ft_get_map_utils_2(t_scene *scene, char **map, int line, int col)
{
	if (map[line][col] == '2' || map[line][col] == '3'
		|| map[line][col] == '4')
		ft_set_sprite(scene, map, line, col);
	else if (map[line][col] == '5' || map[line][col] == '6'
		|| map[line][col] == '7')
		scene->map[line][col] = map[line][col];
	if (map[line][col] == '2')
		scene->pars.sp2 = 1;
	else if (map[line][col] == '3')
		scene->pars.sp3 = 1;
	else if (map[line][col] == '4')
		scene->pars.sp4++;
	else if (map[line][col] == '5')
		scene->pars.fl5 = 1;
	else if (map[line][col] == '6')
		scene->pars.dr6 = 1;
	else if (map[line][col] == '7')
		scene->pars.ex7 = 1;
}
