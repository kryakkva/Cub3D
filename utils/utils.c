/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:34:01 by apaege            #+#    #+#             */
/*   Updated: 2022/03/28 14:34:59 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_mem(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	ft_free_array(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		ft_free_mem(mass[i++]);
	ft_free_mem(mass);
}

int	ft_mass_len(char **mass)
{
	int	i;

	i = 0;
	while (mass[i])
		i++;
	return (i);
}

int	ft_max_len_str(char **mass)
{
	int	i;
	int	len;
	int	max;

	if (!mass)
		return (0);
	i = 0;
	max = 0;
	while (mass[i])
	{
		len = ft_strlen(mass[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
