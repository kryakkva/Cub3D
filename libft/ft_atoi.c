/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:28:51 by apaege            #+#    #+#             */
/*   Updated: 2022/02/08 23:17:25 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_int(long int num, int sign)
{
	if (num > 2147483647)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == ' ') || ((str[i] >= 8) && (str[i] <= 13)))
		i++;
	while (((str[i] == '-') || (str[i] == '+')) && ((str[i + 1] >= '0')
			&& (str[i + 1] <= '9')))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (check_int(num, sign) != 1)
			return (check_int(num, sign));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
