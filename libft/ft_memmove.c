/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:29:38 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:29:40 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *cpy;

	cpy = malloc(len * sizeof(char));
	ft_memcpy(cpy, src, len);
	ft_memcpy(dst, cpy, len);
	free(cpy);
	return (dst);
}
