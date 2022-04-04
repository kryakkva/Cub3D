/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:19 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:31:21 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	while (n / 10 > 0)
	{
		len = len * 10;
		n = n / 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	len;
	int	x;

	len = 1;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = n * (-1);
		}
		len = num_len(n);
		while (len > 0)
		{
			x = n / len + '0';
			write(fd, &x, 1);
			n = n - (x - '0') * len;
			len = len / 10;
		}
	}
}
