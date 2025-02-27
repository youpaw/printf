/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_classifier3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:45:46 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:45:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_representation.h"
#include "double_classifier.h"

int				is_nan(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0x7FFF && dp.bits63_62 == 0x3 && dp.bits61_0 != 0);
}

t_double_parts	get_double_parts(t_double_bit d)
{
	t_double_parts	dp;

	dp.sign = sign(d);
	dp.bit63 = (d.ui[0] >> 63) & 0x1;
	dp.bits63_62 = (d.ui[0] >> 62) & 0x3;
	dp.bits62_0 = d.ui[0] & 0x7FFFFFFFFFFFFFFF;
	dp.bits61_0 = d.ui[0] & 0x3FFFFFFFFFFFFFFF;
	dp.exponent = exponent(d);
	return (dp);
}
