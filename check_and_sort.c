/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 20:37:44 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/21 12:37:07 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftlist.h"

void	reverse_sort(t_directory **begin)
{
	t_directory *cpy;
	t_directory *next;
	t_directory *bfr;

	bfr = *begin;
	cpy = bfr->next;
	bfr->next = NULL;
	while (cpy)
	{
		next = cpy->next;
		cpy->next = bfr;
		bfr = cpy;
		cpy = next;
	}
	*begin = bfr;
}

int		check(t_command *list, char c)
{
	while (list)
	{
		if (list->letter == c)
			return (1);
		list = list->next;
	}
	return (0);
}
