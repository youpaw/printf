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

uint64_t	mantiss(t_double_bit d)
{
	return (d.ui[0]);
}

uint32_t		exponent(t_double_bit d)
{
	return ((int32_t)(d.ui[1] & 0x7FFF));
}

int				msb(uint64_t d)
{
	return (d >> 63);
}

/*
 получаем тип с битами как в заданном дабале, для последуюущих операций над битами
 */
t_double_bit	get_representation(long double d)
{
    t_double_view dw;

    dw.view.ui[0] = 0;
	dw.view.ui[1] = 0;

	dw.ld = d;
	return (dw.view);
}

int				sign(t_double_bit d)
{
	return (d.ui[1] >> 15);
}
