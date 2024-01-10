/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:29:32 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/16 17:18:25 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*truc;
	t_list	*start;

	if (!lst || !f || !del)
		return (NULL);
	truc = ft_lstnew(f(lst->content));
	if (!truc)
		return (NULL);
	start = truc;
	lst = lst->next;
	while (lst)
	{
		truc = ft_lstnew(f(lst->content));
		if (!truc)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&start, truc);
	}
	return (start);
}
