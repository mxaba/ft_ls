/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:38:05 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/27 10:32:09 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

t_command		*new_command(char c)
{
	t_command *new_command;

	new_command = malloc(sizeof(t_command));
	new_command->letter = c;
	new_command->next = NULL;
	return (new_command);
}

void			add_command(t_command **c_lst, char c)
{
	t_command *tmp;

	tmp = *c_lst;
	if (!tmp)
	{
		tmp = new_command(c);
		*c_lst = tmp;
		return ;
	}
		else while (tmp->next)
			tmp = tmp->next;
	tmp->next = new_command(c);
}

void			to_command(char **av, t_command **c_lst)
{
	int g;
	int h;

	if (!av[1])
		return ;
	g = 1;
	h = 1;
	while (av[g])
	{
		if (av[g][0] == '-' && !av[g][1])
			return ;
		while (av[g][0] == '-' && av[g][h])
		{
			if (av[g][1] == '-' && !av[g][2])
				return ;
			add_command(c_lst, av[g][h]);
			++h;
		}
		if (av[g][0] != '-')
			return ;
		h = 1;
		++g;
	}
}
