/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:30:46 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:30:48 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{	
	int	num;

	if (!lst)
		return (0);
	num = 0;
	while (lst)
	{	
		lst = lst->next;
		num++;
	}
	return (num);
}
