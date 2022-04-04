/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:32:05 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:32:07 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	begin(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s1[i] != 0)
	{
		flag = 0;
		j = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (0);
}

static	int	end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = ft_strlen(s1);
	while (i-- > 0)
	{
		flag = 0;
		j = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			return (i + 1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pointer;

	if (!s1)
		return (0);
	if (set == 0)
		return ((char *)s1);
	if (begin(s1, set) == end(s1, set))
	{
		pointer = malloc(sizeof(char));
		pointer[0] = 0;
		return (pointer);
	}
	pointer = malloc((end(s1, set) - begin(s1, set) + 1) * sizeof(char));
	if (pointer == 0)
		return (NULL);
	ft_strlcpy(pointer, s1 + begin(s1, set), end(s1, set) - begin(s1, set) + 1);
	return (pointer);
}
