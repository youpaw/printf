/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:33:33 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:34:20 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"
#include "double_unpacked.h"
#include "unpack_double.h"

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

const char	*special2text(int special)
{
	if (special == DOUBLE_NAN)
		return ("nan");
	if (special == DOUBLE_NAN_SIG)
		return ("nan(sig)");
	if (special == DOUBLE_NAN_IND)
		return ("nan(ind)");
	if (special == DOUBLE_INF)
		return ("nan(inf)");
	return ("Error");
}

char		*print_double_unpacked(const t_double_unpacked *du,
		int total_width, int frac_width, int left_align)
{
	char	*str;

	if (du->special == DOUBLE_NAN || du->special == DOUBLE_INF)
	{
		str = str_create(20);
		str[0] = '-';
		str_copy(str + du->sign, special2text(du->special));
	}
	else
		str = print_double_unpacked_normal(du, frac_width);
	str = correct_total_width(str, total_width, left_align);
	return (str);
}

char		*print_double(long double d, int total_width,
		int fractional_width, int left_align)
{
	t_double_unpacked	du;

	du = unpack_double(d);
	return (print_double_unpacked(&du, total_width, fractional_width,
				left_align));
}
