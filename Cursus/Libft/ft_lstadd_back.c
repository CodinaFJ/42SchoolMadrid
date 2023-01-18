/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:09:36 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 16:09:39 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/**
 * Adds given new node to the back of given list lst.
 * @param lst Pointer to first node in list where to add the new node.
 * @param new Node to add
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	while (node != NULL)
	{
		if (node->next == NULL)
		{
			node->next = new;
			return ;
		}
		node = node->next;
	}
	*lst = new;
}
