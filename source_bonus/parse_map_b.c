/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:12:05 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:15:37 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

static void	ft_get_map_utils(t_scene *scene, char **map, int line)
{
	int	col;

	scene->map[line] = ft_calloc(sizeof(char), scene->size.w + 1);
	scene->map[line][scene->size.w] = '\0';
	col = 0;
	while (map[line][col])
	{
		if (map[line][col] == '1' || map[line][col] == ' ')
			scene->map[line][col] = map[line][col];
		else if (map[line][col] == '0')
			scene->map[line][col] = '9';
		else if (map[line][col] == '2' || map[line][col] == '3'
			|| map[line][col] == '4' || map[line][col] == '5'
			|| map[line][col] == '6' || map[line][col] == '7')
			ft_get_map_utils_2(scene, map, line, col);
		else if (ft_in_charset(map[line][col], "NSWE")
				&& scene->pos.x == -1)
			ft_start_pos_init(scene, map, line, col);
		else
			ft_print_error("Bad map format", PARSE_ERROR);
		col++;
	}
}

static void	ft_get_map(t_scene	*scene, char *join)
{
	int		line;
	char	**map;

	map = ft_split(join, '\n');
	free(join);
	scene->size.h = ft_mass_len(map);
	scene->map = ft_calloc(sizeof(char *), scene->size.h);
	line = 0;
	while (line < scene->size.h)
	{
		scene->size.w = ft_strlen(map[line]);
		ft_get_map_utils(scene, map, line);
		line++;
	}
	scene->size.w = ft_max_len_str(map);
	if (scene->pos.x == -1)
		ft_print_error("Initial position missing", PARSE_ERROR);
	ft_free_array(map);
}

static void	ft_parse_util_2(int fd, char *line, int ret)
{	
	int	fl;
	int	fl_one;

	fl = 0;
	fl_one = 0;
	free(line);
	while (ret == 1)
	{	
		fl_one = 1;
		ret = get_next_line(fd, &line);
		if (line[0])
		{
			free(line);
			ft_print_error("Bad map format", PARSE_ERROR);
		}
		if (ret)
		{
			free(line);
			fl = 1;
			fl_one = 0;
		}
	}
	if (fl || fl_one)
		free(line);
}

static void	ft_parse_util(int fd, char *line, char **join, int ret)
{
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (!line[0])
		{
			ft_parse_util_2(fd, line, ret);
			break ;
		}
		if (ft_only_space_lines(line))
			ft_print_error("Bad map format", PARSE_ERROR);
		ft_join_and_clean(join, line);
		ft_join_and_clean(join, "\n");
		free(line);
	}
}

void	ft_parse_map(t_scene *scene, int fd, char *line)
{
	char	*tmp;
	char	*join;
	int		ret;

	tmp = line;
	join = ft_strdup(line);
	free(tmp);
	ft_join_and_clean(&join, "\n");
	ret = 1;
	ft_parse_util(fd, line, &join, ret);
	ft_get_map(scene, join);
	ft_check_map(scene->map, scene->size);
}
