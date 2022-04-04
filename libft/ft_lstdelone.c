/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaege <apaege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:30:29 by apaege            #+#    #+#             */
/*   Updated: 2021/11/12 19:33:30 by apaege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list	*lst, void (*del)(void*))
{	
	t_list	*ptr;

	if (lst && del)
	{	
		ptr = lst;
		lst = lst->next;
		del(ptr->content);
		free(ptr);
	}
}
