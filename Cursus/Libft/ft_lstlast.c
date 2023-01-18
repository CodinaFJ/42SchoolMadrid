/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:59:12 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 15:59:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/**
 * Returns last node of list
 * @param lst Pointer to first node of the list.
 * @return Pointer to last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node != NULL)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}
