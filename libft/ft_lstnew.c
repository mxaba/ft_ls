/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 12:15:54 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 12:16:01 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*test;

	test = (t_list *)malloc(1 * sizeof(t_list));
	if (!test)
		return (NULL);
	if (!content)
	{
		test->content = NULL;
		test->content_size = 0;
	}
	else
	{
		test->content = malloc(content_size * sizeof(char));
		if (!(test->content))
			return (NULL);
		ft_memmove(test->content, content, content_size);
	}
	test->next = NULL;
	return (test);
}
