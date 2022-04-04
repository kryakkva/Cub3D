/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:29:35 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:29:37 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	sign_rev(int number)
{
	if (number < 0)
		number = -number;
	return (number);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*pointer;
	int		number;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = num_len(n);
	pointer = malloc(sizeof(char) * (len + sign + 1));
	if (pointer == 0)
		return (NULL);
	pointer[len + sign] = 0;
	if (sign)
		pointer[0] = '-';
	while (len > 0)
	{
		number = n % 10;
		number = sign_rev(number);
		pointer[--len + sign] = number + '0';
		n = n / 10;
	}
	return (pointer);
}
