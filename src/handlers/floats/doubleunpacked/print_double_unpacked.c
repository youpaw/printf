/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_unpacked.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:28:53 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:28:56 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "double_unpacked.h"
#include "str.h"
#include "utils.h"

/*
** last digit will be rounded
*/

char	*print_fractional(const t_double_unpacked *du, int width)
{
	int		frac_size;
	char	*str;

	frac_size = width + 1;
	str = str_create(frac_size);
	str_fill(str, frac_size, '0');
	big_int_print(str, frac_size, &du->fractional, 1);
	return (str);
}

char	*print_integer(const t_double_unpacked *du)
{
	int		dec_size;
	char	*str;

	dec_size = big_int_decimal_size(&du->integer);
	str = str_create(dec_size + du->sign);
	str[0] = '-';
	big_int_print(str + du->sign, dec_size, &du->integer, 0);
	return (str);
}

char	*round_helper(char *dbl, int end)
{
	int		carry;
	int		cur;

	carry = 1;
	while (--end >= 0)
	{
		if (dbl[end] == '.')
		{
			dbl[end + 1] = '.';
			continue;
		}
		cur = to_int(dbl[end]) + carry;
		carry = cur / 10;
		dbl[end + 1] = cur % 10 + '0';
	}
	if (carry)
		dbl[0] = '1';
	else
		str_shift_left(dbl);
	return (dbl);
}

char	*round_double_inplace(char *dbl)
{
	int		end;
	int		last;

	end = str_len(dbl) - 1;
	last = to_int(dbl[end]);
	dbl[end] = '\0';
	if (last < 5)
		return (dbl);
	return (round_helper(dbl, end));
}

char	*print_double_unpacked_normal(const t_double_unpacked *du,
		int frac_width)
{
	char	*integ;
	char	*frac;
	char	*dbl_half;
	char	*dbl;

	integ = print_integer(du);
	if (frac_width == 0)
		return (integ);
	frac = print_fractional(du, frac_width);
	dbl_half = str_cat(integ, ".");
	dbl = str_cat(dbl_half, frac);
	free(integ);
	free(frac);
	free(dbl_half);
	dbl = round_double_inplace(dbl);
	return (dbl);
}
