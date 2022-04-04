/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:04 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:31:06 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	if (dst || src)
	{
		s1 = (unsigned char *)dst;
		s2 = (unsigned char *)src;
		if (s1 < s2)
			while (i++ < len)
				s1[i - 1] = s2[i - 1];
		else
			while (len--)
				s1[len] = s2[len];
	}
	return (dst);
}
