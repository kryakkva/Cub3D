/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 23:09:00 by apaege            #+#    #+#             */
/*   Updated: 2022/03/20 23:11:11 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_width(int n, int width)
{
	char	*res;
	char	*tmp;
	int		i;
	int		diff;

	res = malloc(sizeof(char) * (width + 1));
	if (!res)
		return (NULL);
	diff = width - ft_nbrlen(n);
	if (diff > 0)
	{
		i = 0;
		while (i < diff)
			res[i++] = '0';
	}
	tmp = ft_itoa(n);
	ft_memcpy(res + diff, tmp, ft_nbrlen(n));
	free(tmp);
	return (res);
}
