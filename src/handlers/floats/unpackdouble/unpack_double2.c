/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_double2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:23:33 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:58:17 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"
#include "utils.h"
#include "double_representation.h"

void	calc_fractional(t_big_int *fractional, t_double_bit fract,
		int initial_pow, int denormal)
{
	int			width;
	t_big_int	pow;
	t_big_int	pow1;

	width = bit_width(fract) + initial_pow;
	n_pow_y(&pow, 10, width);
	n_pow_y(&pow1, 10, width);
	big_int_create(fractional);
	if (initial_pow)
	{
		while (initial_pow--)
			big_int_divide(&pow, 2);
		if (!denormal)
			big_int_add(fractional, &pow);
	}
	while (fract)
	{
		big_int_divide(&pow, 2);
		if (msb(fract))
			big_int_add(fractional, &pow);
		fract <<= 1;
	}
	big_int_add(fractional, &pow1);
}

void	unpack_below_one(t_big_int *integer, t_big_int *fractional,
		uint32_t e, t_double_bit m)
{
	t_double_bit	fract;

	e = EXPONENT_BIAS - e;
	fract = ((m << (EXPONENT_SIZE_BITS + IMAGINARY_BIT_PRESENT + 1)) &
			representation_mask()) << LEFT_SHIFT_BITS;
	calc_fractional(fractional, fract, e, 0);
	big_int_from_int(integer, 0);
}

void	unpack_average(t_big_int *integer, t_big_int *fractional,
		uint32_t e, t_double_bit m)
{
	t_double_bit	fract;

	m = add_imaginary_bit(m);
	big_int_from_int(integer, m >> (MANTISS_SIZE_BITS -
				IMAGINARY_BIT_PRESENT - e));
	fract = ((m << (EXPONENT_SIZE_BITS + IMAGINARY_BIT_PRESENT + 1 + e)) &
			representation_mask()) << LEFT_SHIFT_BITS;
	calc_fractional(fractional, fract, 0, 0);
}

void	unpack_huge(t_big_int *integer, t_big_int *fractional,
		uint32_t e, t_double_bit m)
{
	t_big_int	mantiss;
	t_big_int	pow;

	(void)fractional;
	m = add_imaginary_bit(m);
	big_int_from_int(&mantiss, m);
	n_pow_y(&pow, 2, e - MANTISS_SIZE_BITS + IMAGINARY_BIT_PRESENT);
	big_int_multiply_big(integer, &pow, &mantiss);
}
