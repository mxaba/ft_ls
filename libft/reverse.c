/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:01:57 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 13:02:02 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		reverse(wchar_t **str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = (ft_strlen_null(*str, 0) - 1);
	if ((*str)[i] == '-')
		i++;
	while (j > i)
	{
		c = (*str)[j];
		(*str)[j] = (*str)[i];
		(*str)[i] = c;
		i++;
		j--;
	}
}
