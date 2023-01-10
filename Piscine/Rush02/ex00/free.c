/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:51:11 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 18:51:13 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include"ft.h"
#include"rush02.h"

void	free_lst(t_entry_str *dict)
{
	t_entry_str	*next_dict;

	free(dict->str);
	next_dict = dict->next;
	free(dict);
	if (dict->next)
		free_lst(next_dict);
	return ;
}

void	free_text_rows(char **text_rows)
{
	int	i;

	i = 0;
	while (text_rows[i])
	{
		free(text_rows[i]);
		i++;
	}
	free(text_rows[i]);
	free(text_rows);
}
