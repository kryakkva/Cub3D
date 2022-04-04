/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:08:30 by apaege            #+#    #+#             */
/*   Updated: 2022/03/12 18:04:38 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_parse_textures(t_scene *scn)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		scn->textures[i] = ft_calloc(sizeof(t_img), 1);
		scn->textures[i]->img_ptr = mlx_xpm_file_to_image(scn->mlx,
				scn->tex[i], &(scn->textures[i]->size.w), \
				&(scn->textures[i]->size.h));
		if (!scn->textures[i]->img_ptr)
			ft_print_error("Texture not found", MLX_ERROR);
		scn->textures[i]->data = mlx_get_data_addr(scn->textures[i]->img_ptr,
				&scn->textures[i]->bits_per_pixel, &scn->textures[i]->size_line,
				&scn->textures[i]->endian);
		if (!scn->textures[i]->data)
			ft_print_error("Data texture error", MLX_ERROR);
		i++;
	}
}

static int	ft_check_line(char **data, char *type)
{
	size_t	size;

	if (!ft_strcmp(data[0], type) && ft_mass_len(data) == 2)
	{
		if (!ft_strcmp(type, "NO") || !ft_strcmp(type, "SO")
			|| !ft_strcmp(type, "WE") ||!ft_strcmp(type, "EA"))
		{
			size = ft_strlen(data[1]) - 4;
			if (ft_strncmp(&data[1][size], ".xpm", 4))
				return (0);
		}
		return (1);
	}
	return (0);
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
		ft_print_error("Invalid line parsing", PARSE_ERROR);
	free(line);
	ft_free_array(data);
}

static t_scene	*ft_parse(int fd)
{
	t_scene	*scn;
	char	*line;

	scn = ft_calloc(sizeof(t_scene), 1);
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
	ft_parse_map(scn, fd);
	return (scn);
}

t_scene	*ft_start_check(int argc, char **argv)
{
	int		fd;
	t_scene	*scene;

	if (argc != 2 || ft_ext(argv[1]) || ft_strncmp(argv[0], "./cub3D", 7))
		ft_print_error("To correct run, write ./cub3D map_name.cub", 1);
	fd = ft_open(argv[1]);
	scene = ft_parse(fd);
	if (!scene)
		ft_print_error("Parsing error", PARSE_ERROR);
	if (close(fd) == -1)
		ft_print_error(strerror(errno), errno);
	return (scene);
}
