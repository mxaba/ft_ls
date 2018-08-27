/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:43:18 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/17 22:33:03 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

int		can_we_open_rec(char *str, t_command *c_lst)
{
	if (str[0] != '.')
		return (1);
	if (ft_strcmp(".", str) != 0 && ft_strcmp("..", str) != 0 &&\
	(check(c_lst, 'A') == 1 || check(c_lst, 'a') == 1))
		return (1);
	return (0);
}

int		rec_error(char **new_name)
{
	ft_printf("%s\n", *new_name);
	perror("error");
	free(*new_name);
	return (0);
}

int		rec_part(t_command *c_lst, char *new_name,\
		t_directory **directory, DIR *tmp)
{
	*directory = dirent_cpy(tmp);
	sort_directory(c_lst, directory);
	ft_printf("%s:\n", new_name);
	read_a_dir_lol(*directory, c_lst, new_name);
	closedir(tmp);
	return (1);
}

int		is_directory(char *name, char *path)
{
	char		*new_name;
	struct stat stat;

	new_name = add_name(path, name);
	lstat(new_name, &stat);
	if (S_ISDIR(stat.st_mode) == 1)
	{
		free(new_name);
		return (1);
	}
	free(new_name);
	return (0);
}

int		aff_with_directory(t_command *c_lst, char *d_name,\
		char *src, char *new_name)
{
	t_directory *directory;
	DIR			*tmp;
	t_directory *begin;

	new_name = add_name(src, d_name);
	tmp = opendir(new_name);
	if (!tmp)
		return (rec_error(&new_name));
	else
		rec_part(c_lst, new_name, &directory, tmp);
	while (directory)
	{
		if (can_we_open_rec(directory->d_name, c_lst) == 1\
		&& is_directory(directory->d_name, new_name) == 1)
		{
			ft_printf("\n");
			aff_with_directory(c_lst, directory->d_name, new_name, NULL);
		}
		begin = directory;
		directory = directory->next;
		free(begin->d_name);
		free(begin);
	}
	free(new_name);
	return (1);
}
