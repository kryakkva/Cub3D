/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:30:50 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:30:51 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, \
		size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	if (dst || src)
	{
		s1 = (char *)dst;
		s2 = (char *)src;
		{
			while (i < n)
			{
				s1[i] = s2[i];
				i++;
				if ((unsigned char)s2[i - 1] == (unsigned char)c)
					return ((char *) &dst[i]);
			}
		}
	}
	return (0);
}
