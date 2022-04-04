/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:01:03 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:14:10 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

int	ft_check_line(char **data, char *type)
{
	size_t	size;

	if (!ft_strcmp(data[0], type) && ft_mass_len(data) == 2)
	{
		if (!ft_strcmp(type, "NO") || !ft_strcmp(type, "SO")
			|| !ft_strcmp(type, "WE") || !ft_strcmp(type, "EA")
			|| !ft_strcmp(type, "SP2") || !ft_strcmp(type, "SP3")
			|| !ft_strcmp(type, "SP4") || !ft_strcmp(type, "FL5")
			|| !ft_strcmp(type, "DR6") || !ft_strcmp(type, "EX7"))
		{
			size = ft_strlen(data[1]) - 4;
			if (ft_strncmp(&data[1][size], ".xpm", 4))
				return (0);
		}
		return (1);
	}
	return (0);
}

static void	ft_set_all_do(t_scene *scene, char **data)
{
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
	else
		ft_print_error("Invalid line parsing", PARSE_ERROR);
}

static void	ft_set_all(t_scene *scene, char *line)
{
	char	**data;

	data = ft_split(line, ' ');
	if (ft_check_line(data, "NO") && !scene->tex[NORTH])
		scene->tex[NORTH] = ft_strdup(data[1]);
	else if (ft_check_line(data, "SO") && !scene->tex[SOUTH])
		scene->tex[SOUTH] = ft_strdup(data[1]);
	else if (ft_check_line(data, "WE") && !scene->tex[WEST])
		scene->tex[WEST] = ft_strdup(data[1]);
	else if (ft_check_line(data, "EA") && !scene->tex[EAST])
		scene->tex[EAST] = ft_strdup(data[1]);
	else if (ft_check_line(data, "F") && !scene->floor)
		ft_set_color(scene, data, 0);
	else if (ft_check_line(data, "C") && !scene->ceil)
		ft_set_color(scene, data, 1);
	else
	{
		ft_set_all_do(scene, data);
		scene->nb_textures++;
	}
	free(line);
	ft_free_array(data);
}

static void	ft_parse(int fd, t_scene *scn)
{
	char	*line;

	ft_init_scene(scn);
	while (get_next_line(fd, &line) == 1)
	{
		if (!line[0])
		{
			free(line);
			continue ;
		}
		else if (ft_only_space_lines(line))
			ft_print_error("Invalid line parsing", PARSE_ERROR);
		ft_set_all(scn, line);
		if (scn->tex[NORTH] && scn->tex[SOUTH] && scn->tex[WEST]
			&& scn->tex[EAST] && scn->floor && scn->ceil)
			break ;
	}
	ft_parse_bonus(fd, scn);
}

void	ft_start_check(t_scene *scene)
{
	int			fd;
	static int	nummap;

	nummap++;
	scene->map_num = nummap;
	if ((scene->argc < nummap + 1) || ft_ext(scene->argv[nummap])
		|| ft_strncmp(scene->argv[0], "./cub3D", 7))
		ft_print_error("To correct run, write ./cub3D map_name.cub", 1);
	fd = ft_open(scene->argv[nummap]);
	ft_parse(fd, scene);
	if (close(fd) == -1)
		ft_print_error(strerror(errno), errno);
}
