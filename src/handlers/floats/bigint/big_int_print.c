/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:14:05 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:16:55 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "big_int.h"
#include "utils.h"
#include "double_unpacked.h"
#include "str.h"

int		print_to_string_imp(char *buff, int size, int i, int *cur_pos)
{
	int		cur;

	cur = i % 10;
	if (i >= 10)
		print_to_string_imp(buff, size, i / 10, cur_pos);
	if (*cur_pos < size)
		buff[(*cur_pos)++] = '0' + cur;
	return (*cur_pos);
}

int		print_to_string(char *buff, int buff_size, int width, int i)
{
	int		cur_pos;
	int		iwidth;
	char	*tmp;
	int		size;

	cur_pos = 0;
	iwidth = int_decimal_size(i);
	while (width >= 0 && (cur_pos + iwidth) < width && cur_pos < buff_size)
		buff[cur_pos++] = '0';
	if (width >= 0)
		return (print_to_string_imp(buff, buff_size, i, &cur_pos));
	else
	{
		tmp = str_create(buff_size + 1);
		str_fill(tmp, buff_size + 1, '0');
		size = print_to_string_imp(tmp, buff_size + 1, i, &cur_pos);
		str_copy(buff, tmp + 1);
		free(tmp);
		return (size - 1);
	}
}

void	big_int_print(char *buff, int buff_size, const t_big_int *big_int,
		int is_frac)
{
	int		num_printed;
	int		i;

	num_printed = (big_int->size == 0)
		? print_to_string(buff, buff_size, 0, 0)
		: print_to_string(buff, buff_size, -is_frac, big_int_back(big_int));
	i = big_int->size - 2;
	while (i >= 0 && num_printed < buff_size)
	{
		num_printed += print_to_string(buff + num_printed,
				buff_size - num_printed, 9, big_int->digits[i]);
		--i;
	}
}
