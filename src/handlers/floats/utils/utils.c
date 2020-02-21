/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:25:54 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:27:13 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "utils.h"
#include "double_representation.h"

size_t	my_max(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}

int		int_decimal_size(int i)
{
	int		size;

	size = 1;
	while (i /= 10)
		++size;
	return (size);
}

int		to_int(char ch)
{
	return (ch - '0');
}

int		bit_width(uint64_t bits)
{
	int		result;

	result = 0;
	while (bits)
	{
		++result;
		bits <<= 1;
	}
	return (result);
}

void	str_shift_left(char *str)
{
	while ((*str = *(str + 1)))
		++str;
}
