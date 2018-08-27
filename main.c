/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:40:21 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/27 10:30:10 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

int		read_a_dir(DIR *file)
{
	struct dirent *tmp;

	tmp = readdir(file);
	while (tmp)
	{
		if (tmp->d_name[0] != '.')
			ft_printf("%s\n", tmp->d_name);
		tmp = readdir(file);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;
	DIR *tmp;

	i = 1;
	to_parsing(argv);
	return (1);
}
