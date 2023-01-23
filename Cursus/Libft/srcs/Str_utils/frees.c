/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:22:16 by jcodina-          #+#    #+#             */
/*   Updated: 2023/01/16 20:22:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/**
 * Used to protect memory space s from allocation error.
 * @return NULL if s == NULL, after freeing the allocated space for s.
 * Otherwise return s.
 */
void	*prot_malloc(void *s)
{
	if (s == NULL)
	{
		free(s);
		return (NULL);
	}
	return (s);
}

/**
 * Used to protect double pointer array p form allocation error.
 * Liberates n arrays in p and p.
 * @param p Double pointer to liberate recursively.
 * @param n Number of arrays in p to free. 
 * @return NULL
 */
void	*free_darray(void **p, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}
