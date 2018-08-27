/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:39:52 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/22 15:13:45 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

void	erraz_directory(t_directory **d)
{
	t_directory *c;

	while (*d)
	{
		c = (*d)->next;
		free((*d)->d_name);
		free(*d);
		*d = c;
	}
}

void	sort_directory(t_command *c_lst, t_directory **d)
{
	if (check(c_lst, 't') == 1)
		sort_by_time(*d, d);
	else
		sort_by_alpha(*d, d);
	if (check(c_lst, 'r') == 1)
		reverse_sort(d);
}

int		display_simple(char *str, t_command *c_lst)
{
	other_command(str, c_lst, 1);
	if ((check(c_lst, 'l') + check(c_lst, 'o')\
		+ check(c_lst, 'g')) > 0)
		aff_rights(str, 1, c_lst, 1);
	ft_printf("%s\n", str);
	return (1);
}

int		display_simple_file(t_file **f_lst, t_command *c_lst, int i)
{
	struct stat tmp;

	if (!*f_lst || !(*f_lst)->name)
		return (0);
	errno = 0;
	stat((*f_lst)->name, &tmp);
	if (errno != 0)
	{
		ft_printf("ft_ls: %s : ", (*f_lst)->name);
		perror(NULL);
		*f_lst = (*f_lst)->next;
		return (display_simple_file(f_lst, c_lst, ++i));
	}
	if (S_ISDIR(tmp.st_mode) == 0)
	{
		display_simple((*f_lst)->name, c_lst);
		*f_lst = (*f_lst)->next;
		return (display_simple_file(f_lst, c_lst, ++i));
	}
	else
		return (i);
}

int		ft_ls(t_command *c_lst, t_file *f_lst)
{
	struct stat tmp;
	t_file		*begin;

	begin = f_lst;
	if (!f_lst || !f_lst->name)
		return (display_here(c_lst));
	if (display_simple_file(&f_lst, c_lst, 0) != 0)
		ft_printf("\n");
	if (!c_lst)
		just_display(f_lst);
	else
		display_everywhere(c_lst, f_lst);
	f_lst = begin;
	return (1);
}
