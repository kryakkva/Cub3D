/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:28:52 by apaege            #+#    #+#             */
/*   Updated: 2022/03/23 19:10:42 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_ext(char *name)
{
	size_t	size;

	size = ft_strlen(name);
	size -= 4;
	return (ft_strncmp(&name[size], ".cub", 4));
}

int	ft_open(char *map)
{
	int	fd;

	if (open(map, O_DIRECTORY) != -1)
		ft_print_error("Opened map is directory", OPEN_ERROR);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_print_error(strerror(errno), errno);
	return (fd);
}
