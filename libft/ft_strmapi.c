/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:51 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:31:53 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*pointer;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	pointer = malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	while (i < len)
	{
		pointer[i] = f(i, s[i]);
		i++;
	}
	pointer[i] = 0;
	return (pointer);
}
