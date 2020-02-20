/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_double1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:22:03 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:58:51 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unpack_double.h"
#include "big_int.h"
#include "double_unpacked.h"
#include "double_representation.h"
#include "double_classifier.h"

t_double_unpacked	assign_double_unpacked(int sign, t_big_int *integer,
		t_big_int *fractional, int special)
{
	t_double_unpacked	result;

	result.sign = sign;
	result.integer = *integer;
	result.fractional = *fractional;
	result.special = special;
	return (result);
}

void				unpack_denormal(t_big_int *integer, t_big_int *fractional,
		t_double_bit mantiss)
{
	t_double_bit fract;

	big_int_from_int(integer, 0);
	fract = ((mantiss << (EXPONENT_SIZE_BITS + 2)) &
			representation_mask()) << LEFT_SHIFT_BITS;
	calc_fractional(fractional, fract, EXPONENT_BIAS - 1, 1);
}

void				unpack_normal(t_big_int *integer, t_big_int *fractional,
		t_double_bit representation, t_double_bit m)
{
	uint32_t e;

	e = exponent(representation);
	if (e < EXPONENT_BIAS)
		unpack_below_one(integer, fractional, e, m);
	else
	{
		e -= EXPONENT_BIAS;
		if (e <= MANTISS_SIZE_BITS)
			unpack_average(integer, fractional, e, m);
		else
			unpack_huge(integer, fractional, e, m);
	}
}

int					classify(t_double_bit rep, t_big_int *integer,
		t_big_int *fractional)
{
	int		class;

	class = 0;
	if (is_zero(rep))
	{
		big_int_from_int(integer, 0);
		big_int_from_int(fractional, 0);
	}
	else if (is_inf(rep))
		class = DOUBLE_INF;
	else if (is_nan(rep))
		class = DOUBLE_NAN;
	else if (is_ind(rep))
		class = DOUBLE_NAN_IND;
	else if (is_nan_sig(rep))
		class = DOUBLE_NAN_SIG;
	else if (is_denormal(rep))
		unpack_denormal(integer, fractional, mantiss(rep));
	else
		unpack_normal(integer, fractional, rep, mantiss(rep));
	return (class);
}

t_double_unpacked	unpack_double(long double d)
{
	t_double_bit	rep;
	t_big_int		fractional;
	t_big_int		integer;
	int				special;

	big_int_create(&fractional);
	big_int_create(&integer);
	rep = get_representation(d);
	special = classify(rep, &integer, &fractional);
	return (assign_double_unpacked(sign(rep), &integer, &fractional, special));
}
