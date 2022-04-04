/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:31:26 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:34:14 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**clear_mass(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static	unsigned	int	ft_num_str(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_str;

	if (!*s)
		return (0);
	i = 0;
	num_str = 0;
	while ((s[i] != 0) && (s[i] == c))
		i++;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			num_str++;
			while ((s[i] != 0) && (s[i] == c))
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		num_str++;
	return (num_str);
}

static	char	*cut_next_str(char *next_str,	unsigned	int	*next_str_len, \
							char c)
{
	unsigned int	i;

	next_str = next_str + *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (*next_str == c)
		(next_str)++;
	while (next_str[i])
	{
		if (next_str[i] == c)
			return (next_str);
		(*next_str_len)++;
		i++;
	}	
	return (next_str);
}

static char	**get_mass(char const *s, char c, unsigned int num_str, \
						char **str)
{
	char				*next_str;
	unsigned int		i;
	unsigned int		next_str_len;

	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < num_str)
	{
		next_str = cut_next_str(next_str, &next_str_len, c);
		str[i] = malloc(sizeof(char) * (next_str_len + 1));
		if (!str[i])
			return (clear_mass(str));
		ft_strlcpy(str[i], next_str, next_str_len + 1);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char				**str;
	unsigned int		num_str;

	if (!s)
		return (0);
	num_str = ft_num_str(s, c);
	str = malloc(sizeof(char *) * (num_str + 1));
	if (!str)
		return (NULL);
	return (get_mass(s, c, num_str, str));
}
