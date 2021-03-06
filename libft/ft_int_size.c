/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:11:22 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:11:25 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_size(int n)
{
	int i;

	i = 1;
	if (n > -2147483648 && n < 2147483647)
	{
		if (n < 0)
		{
			n = -n;
			i++;
		}
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
	}
	else if (n == -2147483648)
		i = 11;
	else if (n == 2147483647)
		i = 10;
	else
		return (0);
	return (i);
}
