/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:19:57 by jcodina-          #+#    #+#             */
/*   Updated: 2022/11/20 16:07:07 by miferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH02_H
# define RUSH02_H

typedef struct s_entry_str
{
	unsigned long		nbr;
	char				*str;
	struct s_entry_str	*next;
}				t_entry_str;

int				calc_rows(char *file_text);
int				calc_buffer(char *path);
char			*row_to_str(char *str, int *error);
unsigned long	*nums_to_divide(t_entry_str *dict, int rows);
int				calc_rows(char *file_text);
int				*calc_size_rows(char *file_text, int rows);
char			**divide_file_text(char *file_text, int rows);
char			**rmv_cr(char	**text_rows);
int				read_file(char *path, int buf_size, char **file_text);
unsigned long	ul_atoi(char *str);
void			nbr_to_str(unsigned long nbr, t_entry_str *dict,
					unsigned long *nums_to_div, int i);
void			free_lst(t_entry_str *dict);
void			free_text_rows(char **text_rows);
t_entry_str		*fill_dict(char **text_rows, int row,
					t_entry_str *new_entry, int *error);
char			*get_str_from_num(unsigned long nbr, t_entry_str *dict);

#endif
