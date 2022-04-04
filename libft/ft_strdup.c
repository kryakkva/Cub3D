/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:32 by apaege            #+#    #+#             */
/*   Updated: 2022/03/13 18:31:31 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pointer;
	int		len;

	len = ft_strlen(s);
	pointer = malloc(len * sizeof(char) + 1);
	if (pointer == 0)
		exit (EXIT_FAILURE);
	else
	{
		ft_strlcpy(pointer, s, len + 1);
		return (pointer);
	}
}
