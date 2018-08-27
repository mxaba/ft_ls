/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:39:10 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/17 22:26:58 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

void	display_everywhere_sncd(t_command *c_lst, t_file *file_list,\
		t_directory *directory, t_directory **begin)
{
	t_directory *cpy;

	if (check(c_lst, 'R') == 1)
	{
		while (directory)
		{
			if (can_we_open_rec(directory->d_name, c_lst) == 1\
			&& is_directory(directory->d_name, file_list->name) == 1)
			{
				ft_printf("\n");
				aff_with_directory(c_lst,\
				directory->d_name, file_list->name, NULL);
			}
			cpy = directory;
			directory = directory->next;
			free(cpy->d_name);
			free(cpy);
		}
	}
	else
		erraz_directory(begin);
}

int		display_everywhere(t_command *c_lst, t_file *file_list)
{
	t_directory *directory;
	DIR			*tmp;
	t_directory **begin;

	if (!file_list)
		return (1);
	tmp = opendir(file_list->name);
	if (!tmp)
		perror("Error");
	else
	{
		directory = dirent_cpy(tmp);
		sort_directory(c_lst, &directory);
		ft_printf("%s:\n", file_list->name);
		read_a_dir_lol(directory, c_lst, file_list->name);
		closedir(tmp);
		begin = &directory;
		display_everywhere_sncd(c_lst, file_list, directory, begin);
	}
	file_list = file_list->next;
	if (file_list)
		ft_printf("\n");
	return (display_everywhere(c_lst, file_list));
}

void	display_here_scnd(t_command *c_lst, t_directory *directory)
{
	t_directory *cpy;

	while (directory)
	{
		if (can_we_open_rec(directory->d_name, c_lst) == 1\
		&& is_directory(directory->d_name, ".") == 1)
		{
			ft_printf("\n");
			aff_with_directory(c_lst, directory->d_name, ".", NULL);
		}
		directory = directory->next;
	}
}

int		display_here(t_command *c_lst)
{
	DIR			*tmp;
	t_directory *directory;
	t_directory **begin;

	tmp = opendir(".");
	directory = dirent_cpy(tmp);
	sort_directory(c_lst, &directory);
	if (check(c_lst, 'R') == 1)
		ft_printf(".:\n");
	read_a_dir_lol(directory, c_lst, ".");
	begin = &directory;
	if (check(c_lst, 'R') == 1)
		display_here_scnd(c_lst, directory);
	erraz_directory(begin);
	closedir(tmp);
	return (1);
}

int		just_display(t_file *file_list)
{
	DIR			*tmp;
	t_directory *directory;

	while (file_list)
	{
		tmp = opendir(file_list->name);
		if (!tmp)
			perror("Error");
		else
		{
			ft_printf("%s:\n", file_list->name);
			directory = dirent_cpy(tmp);
			sort_by_alpha(directory, &directory);
			read_a_dir_lol(directory, NULL, file_list->name);
			closedir(tmp);
			if (file_list->next)
				ft_printf("\n");
			erraz_directory(&directory);
		}
		file_list = file_list->next;
	}
	return (1);
}
