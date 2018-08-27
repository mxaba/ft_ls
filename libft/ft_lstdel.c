/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:14:39 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:14:42 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		**new;
	t_list		**test;

	if (!alst)
		return ;
	new = alst;
	while (*new)
	{
		test = new;
		del((*new)->content, (*new)->content_size);
		free(*test);
		*new = (*new)->next;
	}
	ft_memdel((void **)alst);
}
