/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftlist.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:06:28 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/21 12:28:44 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTLIST_H
# define LIBFTLIST_H

# include "libft/libft.h"
# include <dirent.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>

# include <grp.h>
# include <pwd.h>
# include <stdlib.h>
# include <limits.h>
# include <wchar.h>
# include <sys/xattr.h>
# include <errno.h>

typedef struct			s_command
{
	char				letter;
	struct s_command	*next;
}						t_command;

typedef struct			s_file
{
	char				*name;
	struct s_file		*next;
}						t_file;

typedef struct			s_directory
{
	ino_t				d_ino;
	off_t				d_off;
	unsigned short		d_reclen;
	unsigned char		d_type;
	char				*d_name;
	struct s_directory	*next;
}						t_directory;

int						display_everywhere(t_command *c_lst,\
						t_file *f_lst);
int						display_here(t_command *c_lst);
int						just_display(t_file *f_lst);
int						sort_by_type(t_file *file, t_file **begin);
int						to_parsing(char **av);
void					to_command(char **av, t_command **c_lst);
void					to_file(char **av, t_file **file);
int						ft_ls(t_command *c_lst, t_file *f_lst);
int						sort_by_alpha(t_directory *dir, t_directory **begin);
int						sort_by_time(t_directory *dir, t_directory **begin);
void					reverse_sort(t_directory **begin);
int						check(t_command *list, char c);
void					time_read(struct stat user, int i, int j);
t_directory				*dirent_cpy(DIR *file);
int						read_a_dir_lol(t_directory *dir,\
						t_command *c_lst, char *path);
void					reverse_sort_file(t_file **begin);
int						sort_by_alpha_file(t_file *file, t_file **begin);
int						aff_with_directory(t_command *c_lst,\
						char *d_name, char *src, char *new_name);
int						aff_rights(char *str, int i,\
						t_command *c_lst, int g);
int						count(off_t size);
char					*add_name(char *str, char *src);
int						can_we_open(char *str, t_command *c_lst);
int						to_parsing(char **tab);
void					other_command(char *str, t_command *c_lst,\
						int block_max);
int						read_a_dir_lol(t_directory *dir,\
						t_command *c_lst, char *path);
void					color(t_directory *dir, char *path, int l);
void					aff_size(off_t size, int max_size);
void					erraz_directory(t_directory **d);
int						can_we_open_rec(char *str, t_command *c_lst);
void					sort_directory(t_command *c_lst,\
						t_directory **directory);
void					display_help_menu(void);
int						is_directory(char *name, char *path);
int						aff_users(struct stat user, int i,\
						t_command *c_lst, int g);
int						max_size_check(t_directory *dir, char *path,\
						t_command *c_lst, int *block_max);
int						max_link_check(t_directory *dir, char *path);
char					*add_name(char *str, char *src);

#endif
