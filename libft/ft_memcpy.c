/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:00 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:31:02 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (dst || src)
	{
		s1 = (unsigned char *)dst;
		s2 = (unsigned char *)src;
		while (n-- != 0)
			s1[n] = s2[n];
	}
	return (dst);
}
