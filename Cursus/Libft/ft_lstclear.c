/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:27:04 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 16:27:05 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/**
 * Removes and liberates node lst and all consucutives.
 * @param lst Node where to start removing nodes.
 * @param del Function used to remove content of each node
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_next;

	node = *lst;
	while (node != NULL)
	{
		node_next = node->next;
		if (node != NULL && del != NULL)
		{
			(*del)(node->content);
			free(node);
		}
		node = node_next;
	}
	*lst = NULL;
}
