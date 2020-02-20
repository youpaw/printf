/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_classifier1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:48:50 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:46:12 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_representation.h"
#include "double_classifier.h"

int		is_zero(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0 && dp.bit63 == 0 && dp.bits62_0 == 0);
}

int		is_denormal(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0 && dp.bit63 == 0 && dp.bits62_0 != 0);
}

int		is_inf(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0x7FFF && dp.bits63_62 == 0x2 && dp.bits61_0 == 0);
}

int		is_nan_sig(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0x7FFF && dp.bits63_62 == 0x2 && dp.bits61_0 != 0);
}

int		is_ind(t_double_bit d)
{
	t_double_parts	dp;

	dp = get_double_parts(d);
	return (dp.exponent == 0x7FFF && dp.bits63_62 == 0x3 && dp.bits61_0 == 0);
}
