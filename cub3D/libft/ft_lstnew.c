/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpuig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:41:46 by qpuig             #+#    #+#             */
/*   Updated: 2023/02/16 13:51:21 by qpuig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*truc;

	truc = malloc(sizeof(t_list));
	if (!truc)
		return (NULL);
	truc->content = content;
	truc->next = NULL;
	return (truc);
}
