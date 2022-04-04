/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:29 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:31:31 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char)c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *) &str[i]);
	return (0);
}
