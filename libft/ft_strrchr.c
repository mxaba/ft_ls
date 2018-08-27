/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:54:11 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:54:13 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int nb;

	i = 0;
	nb = -1;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			nb = i;
		i++;
	}
	if (str[i] == (unsigned char)c)
		nb = i;
	if (nb != -1)
		return ((char *)(str + nb));
	else
		return (NULL);
}
