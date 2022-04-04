/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:08:10 by apaege            #+#    #+#             */
/*   Updated: 2022/04/03 19:33:12 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_b.h"

void	ft_swap_int(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_dbl(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_spr(t_int *a, t_int *b)
{
	t_int	c;

	c = *a;
	*a = *b;
	*b = c;
}
