/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:10:27 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:12:27 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "big_int.h"
#include "utils.h"

int		big_int_decimal_size(const t_big_int *bi)
{
	return (int_decimal_size(bi->digits[bi->size - 1]) + 9 * (bi->size - 1));
}

void	big_int_from_int(t_big_int *a, t_double_bit b)
{
	int	digit;

	big_int_create(a);
	digit = b % BIGINT_BASE;
	big_int_push_back(a, digit);
	while (b /= BIGINT_BASE)
	{
		digit = b % BIGINT_BASE;
		big_int_push_back(a, digit);
	}
}
