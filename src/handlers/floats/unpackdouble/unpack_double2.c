/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_double2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:23:33 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/21 15:48:35 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_int.h"
#include "utils.h"
#include "double_representation.h"

void	calc_fractional(t_big_int *fractional, uint64_t fract,
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
		uint32_t e, uint64_t m)
{
	uint64_t	fract;

	e = EXPONENT_BIAS - e;
	fract = m << 1;
	calc_fractional(fractional, fract, e, 0);
	big_int_from_int(integer, 0);
}

/*
** в этой версии double (расширенная - 80 бит) старший бит в мантиссе всегда
** относится к целой части
*/

void	unpack_average(t_big_int *integer, t_big_int *fractional,
		uint32_t e, uint64_t m)
{
	uint64_t	fract;

	big_int_from_int(integer, m >> (63 - e));
	fract = m << (1 + e);
	calc_fractional(fractional, fract, 0, 0);
}

void	unpack_huge(t_big_int *integer, t_big_int *fractional,
		uint32_t e, uint64_t m)
{
	t_big_int	mantiss;
	t_big_int	pow;

	(void)fractional;
	big_int_from_int(&mantiss, m);
	n_pow_y(&pow, 2, e - MANTISS_SIZE_BITS + IMAGINARY_BIT_PRESENT);
	big_int_multiply_big(integer, &pow, &mantiss);
}
