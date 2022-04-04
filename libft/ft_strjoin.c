/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:36 by apaege            #+#    #+#             */
/*   Updated: 2022/03/13 18:31:38 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	len1;
	size_t	len2;

	if ((!s1) || (!s2))
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	pointer = malloc((len1 + len2) * sizeof(char) + 1);
	if (pointer == 0)
		exit (EXIT_FAILURE);
	ft_strlcpy(pointer, s1, len1 + 1);
	ft_strlcpy(pointer + len1, s2, len2 + 1);
	return (pointer);
}
