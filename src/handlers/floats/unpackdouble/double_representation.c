/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_representation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:57:12 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:09:10 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_representation.h"

t_double_bit	mantiss(t_double_bit d)
{
	t_double_bit	v;
	t_double_bit	vv;

	v = 0x0000FFFFFFFFFFFF;
	vv = (v << 16) | 0xFFFFFFFFFFFFFFFF;
	return (d & vv);
}

uint32_t		exponent(t_double_bit d)
{
	t_double_bit	v;
	t_double_bit	vv;

	v = 0x7FFF000000000000;
	vv = v << 16;
	return ((int32_t)((d & vv) >> MANTISS_SIZE_BITS));
}

int				msb(t_double_bit d)
{
	return (d >> (UNDERLYING_TYPE_SIZE - 1));
}

/*
** no imaginary bit in extended precision
*/

t_double_bit	add_imaginary_bit(t_double_bit d)
{
	return (d);
}

t_double_bit	representation_mask(void)
{
	t_double_bit	v;
	t_double_bit	vv;

	v = 0xFFFFFFFFFFFFFFFF;
	vv = (v << 16) | 0xFFFF;
	return (vv);
}

t_double_bit	get_representation(long double d)
{
    t_double_view dw;
	
	dw.ld = d;
	return (dw.view);
}

int				sign(t_double_bit d)
{
	return (d >> (EXPONENT_SIZE_BITS + MANTISS_SIZE_BITS));
}
