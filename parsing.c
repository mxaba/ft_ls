/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:41:50 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/24 09:03:10 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

static void	erraz_command(t_command **c_lst)
{
	t_command *cpy;

	while (*c_lst)
	{
		cpy = (*c_lst)->next;
		free(*c_lst);
		*c_lst = cpy;
	}
}

static void	erraz_file(t_file **f_list)
{
	t_file *cpy;

	while (*f_list)
	{
		cpy = (*f_list)->next;
		free((*f_list)->name);
		free(*f_list);
		*f_list = cpy;
	}
}

int			check_letter(char c)
{
	if (c == 'A' || c == 'a' || c == 's' || c == 'i')
		return (1);
	if (c == 'c' || c == 't' || c == 'R' || c == 'r')
		return (1);
	if (c == 'l' || c == '1' || c == 'o' || c == 'g')
		return (1);
	if (c == 'h')
		return (1);
	return (0);
}

int			check_invalid_command(t_command *c_lst)
{
	while (c_lst)
	{
		if (check_letter(c_lst->letter) == 1)
			c_lst = c_lst->next;
		else
			return (0);
	}
	return (1);
}

int			to_parsing(char **av)
{
	t_command	*c_lst;
	t_file		*f_list;
	t_file		**aff;

	c_lst = NULL;
	to_command(av, &c_lst);
	if (check(c_lst, 'h') == 1)
		display_help_menu();
	to_file(av, &f_list);
	if (f_list && f_list->name)
	{
		sort_by_alpha_file(f_list, &f_list);
		if (check(c_lst, 'r') == 1)
			reverse_sort_file(&f_list);
		sort_by_type(f_list, &f_list);
	}
	if (check_invalid_command(c_lst) == 0)
		ft_printf("{red}Bad option{eoc}\n");
	else
		ft_ls(c_lst, f_list);
	erraz_command(&c_lst);
	erraz_file(&f_list);
	return (1);
}
