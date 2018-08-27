/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:49:38 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:49:40 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int i;
	int count;

	i = 0;
	count = ft_strlen(str1);
	while (str2[i])
	{
		str1[count + i] = str2[i];
		i++;
	}
	str1[count + i] = '\0';
	return (str1);
}
