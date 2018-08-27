/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 21:03:17 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/24 09:07:52 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

void		six_month(struct stat user, int i, int j)
{
	char *str;
	char *src;

	src = ft_strdup(ctime(&user.st_mtime));
	str = ft_strnew(ft_strlen(src));
	while (i != 4)
		++i;
	while (i != 11)
	{
		str[j] = src[i];
		++i;
		++j;
	}
	while (i != 19)
		++i;
	while (i != 24)
	{
		str[j] = src[i];
		++i;
		++j;
	}
	ft_printf("%s ", str);
	free(src);
	free(str);
}

void		time_read(struct stat user, int i, int j)
{
	char				*str;
	char				*src;
	unsigned long long	f_time;

	f_time = time(NULL) - user.st_mtime;
	if (f_time >= 30 * 6 * 24 * 3600)
	{
		six_month(user, 0, 0);
		return ;
	}
	src = ft_strdup(ctime(&user.st_mtime));
	str = ft_strnew(ft_strlen(src));
	while (i != 4)
		++i;
	while (i != 16)
	{
		str[j] = src[i];
		++i;
		++j;
	}
	ft_printf("%s ", str);
	free(src);
	free(str);
}
