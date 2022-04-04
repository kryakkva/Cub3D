/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:32:09 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:32:10 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*pointer;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		pointer = malloc(1);
		if (pointer == 0)
			return (NULL);
		pointer[0] = 0;
		return (pointer);
	}
	str_len = ft_strlen(s + start);
	if (str_len < len)
		len = str_len;
	pointer = malloc(len * sizeof(char) + 1);
	if (pointer == 0)
		return (NULL);
	ft_strlcpy(pointer, &s[start], len + 1);
	return (pointer);
}
