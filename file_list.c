/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:39:34 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/21 12:36:39 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

char		*add_name(char *str, char *src)
{
	char	*cpy;
	int		i;
	int		g;

	i = 0;
	g = 0;
	if (!str)
		return (src);
	cpy = malloc((ft_strlen(str) + ft_strlen(src) + 2) * sizeof(char));
	while (str[i])
	{
		cpy[i] = str[i];
		++i;
	}
	if (str[i - 1] != '/')
		cpy[i++] = '/';
	while (src[g])
		cpy[i++] = src[g++];
	cpy[i++] = '\0';
	return (cpy);
}

t_file		*new_file(char *str)
{
	t_file *new_file;

	new_file = malloc(sizeof(t_file));
	new_file->name = ft_strdup(str);
	new_file->next = NULL;
	return (new_file);
}

void		add_file(t_file **file, char *str)
{
	t_file *tmp;

	tmp = *file;
	if (!(*file)->name)
	{
		free(*file);
		tmp = new_file(str);
		*file = tmp;
		return ;
	}
		else while (tmp->next)
			tmp = tmp->next;
	tmp->next = new_file(str);
}

void		check_stop_command(char *str, int *stop)
{
	if (*stop == 1)
		return ;
	if (ft_strcmp(str, "--") == 0 || str[0] != '-')
		*stop = 1;
}

void		to_file(char **av, t_file **file)
{
	int g;
	int stop;

	stop = 0;
	g = 1;
	*file = malloc(sizeof(t_file));
	(*file)->name = NULL;
	(*file)->next = NULL;
	while (av[g])
	{
		if (ft_strcmp(av[g], "-") == 0)
			stop = 1;
		if (av[g][0] != '-' || stop == 1)
			add_file(file, av[g]);
		check_stop_command(av[g], &stop);
		++g;
	}
}
