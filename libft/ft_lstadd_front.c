/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:30:21 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:30:22 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list	**lst,	t_list *new)
{	
	if (lst && new)
	{	
		new->next = *lst;
		*lst = new;
	}
}
