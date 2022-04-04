/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:29:04 by apaege            #+#    #+#             */
/*   Updated: 2022/03/10 21:05:47 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t count)
{
	void	*pointer;

	pointer = malloc(size * count);
	if (pointer == NULL)
		exit (EXIT_FAILURE);
	ft_bzero(pointer, count * size);
	return (pointer);
}
