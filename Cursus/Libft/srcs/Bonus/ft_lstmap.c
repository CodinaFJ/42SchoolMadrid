/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:54 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/18 16:53:55 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void static	*protect_fcont(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	return (NULL);
}

t_list static	*ft_start_lst(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = ft_lstnew(NULL);
	if (new_lst == NULL)
		return (NULL);
	new_lst->content = (*f)(lst->content);
	if (new_lst->content == NULL)
		return (protect_fcont(new_lst, del));
	return (new_lst);
}
/**
 * Iterates through list lst and applies function f to content of each node.
 * Returns list result of the application of function f to each node.
 * @param lst List to iterate through.
 * @param f Function to apply to each node.
 * @param del Function to delete content of nodes in list
 * @return List result of the application of function f to each node 
 * in list lst
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_node_pre;
	t_list	*new_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = ft_start_lst(lst, f, del);
	lst = lst->next;
	new_node_pre = new_lst;
	while (lst != NULL)
	{
		new_node = ft_lstnew(NULL);
		if (new_node == NULL)
			return (NULL);
		new_node->content = (*f)(lst->content);
		if (new_node->content == NULL)
			return (protect_fcont(new_node, del));
		new_node_pre->next = new_node;
		new_node_pre = new_node_pre->next;
		lst = lst->next;
	}
	return (new_lst);
}
