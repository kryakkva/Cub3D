/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:08:40 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 18:06:51 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_join_and_clean(char **str1, char *str2)
{
	char	*tmp;

	tmp = *str1;
	*str1 = ft_strjoin(*str1, str2);
	free (tmp);
}

int	ft_only_space_lines(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_skip_empty_lines(int fd, char **line)
{
	while (get_next_line(fd, line) == 1)
	{
		if (*line[0])
			break ;
		free(*line);
	}
}

void	ft_offset(t_double *dir, double angle)
{
	double	x;
	double	y;

	x = dir->x;
	y = dir->y;
	dir->x = x * cos(angle) - y * sin(angle);
	dir->y = x * sin(angle) + y * cos(angle);
}
