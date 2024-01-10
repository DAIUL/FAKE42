/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:51:27 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/16 16:10:43 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*truc;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		truc = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = truc;
	}
}
