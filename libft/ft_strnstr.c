/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:58 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:32:00 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*str2 == 0)
		return ((char *)str1);
	while ((str1[i] != '\0') && (i < len))
	{
		j = 0;
		if (str1[i] == str2[j])
		{
			while ((str2[j] != '\0') && (str1[i + j] == str2[j])
				&& ((i + j) < len))
			{
				j++;
				if (str2[j] == '\0')
					return ((char *) &str1[i]);
			}
		}
		i++;
	}
	return (0);
}
