/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 13:02:25 by mxaba             #+#    #+#             */
/*   Updated: 2018/08/14 13:02:27 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static wchar_t		*second_test_conv(const char *format, va_list ap, \
					int *i, int *count)
{
	if (format[*i] == 'j')
	{
		++*i;
		return (first_letter_test_j(format[*i], ap, count));
	}
	else if (format[*i] == 'z')
	{
		++*i;
		return (first_letter_test_z(format[*i], ap, count));
	}
	else
		return (first_test(format[*i], ap, count));
}

wchar_t				*check_conv_flags(const char *format, va_list ap, \
					int *i, int *count)
{
	if (format[*i] == 'l')
	{
		++*i;
		if (format[*i] == 'l')
		{
			++*i;
			return (first_letter_test_ll(format[*i], ap, count));
		}
		return (first_letter_test_l(format[*i], ap, count));
	}
	else if (format[*i] == 'h')
	{
		++*i;
		if (format[*i] == 'h')
		{
			++*i;
			return (first_letter_test_hh(format[*i], ap, count));
		}
		return (first_letter_test_h(format[*i], ap, count));
	}
	else
		return (second_test_conv(format, ap, i, count));
}
