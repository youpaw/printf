/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:33:33 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/21 15:41:03 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "double_unpacked.h"
#include "unpack_double.h"
#include "print_double.h"

char		*correct_total_width(char *str, int total_width, int left_align)
{
	int		size;
	char	*new_str;

	size = str_len(str);
	if (total_width <= size)
		return (str);
	new_str = str_create(total_width);
	str_fill(new_str, total_width, ' ');
	if (!left_align)
		str_copy(new_str + total_width - size, str);
	else
	{
		str_copy(new_str, str);
		new_str[size] = ' ';
	}
	free(str);
	return (new_str);
}

const char	*special2text(int special, int upper_case)
{
	if (special == DOUBLE_NAN)
		return (upper_case ? "NAN" : "nan");
	if (special == DOUBLE_NAN_SIG)
		return (upper_case ? "NAN(SIG)" : "nan(sig)");
	if (special == DOUBLE_NAN_IND)
		return (upper_case ? "NAN" : "nan");
	if (special == DOUBLE_INF)
		return (upper_case ? "INF" : "inf");
	return ("Error");
}

/*
** готовим строку к печати
** минус затираем, если флаг du-> sign == 0
*/

char		*print_double_unpacked(const t_double_unpacked *du,
		t_double_options *options)
{
	char	*str;

	if (du->special != DOUBLE_NORMAL)
	{
		str = str_create(20);
		str[0] = '-';
		str_copy(str + du->sign, special2text(du->special, options->big_f));
	}
	else
		str = print_double_unpacked_normal(du, options->fractional_width);
	str = correct_total_width(str, options->total_width, options->left_align);
	return (str);
}

char		*print_double(long double d, t_double_options *options)
{
	t_double_unpacked	du;

	du = unpack_double(d);
	return (print_double_unpacked(&du, options));
}
