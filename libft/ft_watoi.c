/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:59:42 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:59:45 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wsign(wchar_t c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

long			ft_watoi(const wchar_t *str)
{
	int		i;
	int		sign;
	long	temp;
	long	nb;

	i = 0;
	temp = 0;
	nb = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'\
			|| str[i] == '\v' || str[i] == '\f') && str[i])
	{
		i++;
	}
	sign = ft_wsign(str[i]);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb = temp + str[i] - '0';
		temp = nb * 10;
		i++;
	}
	nb = nb * sign;
	return (nb);
}
