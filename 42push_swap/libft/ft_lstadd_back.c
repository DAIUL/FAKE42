/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:46:24 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/16 15:08:26 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*truc;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		truc = ft_lstlast(*lst);
		truc->next = new;
	}
}
