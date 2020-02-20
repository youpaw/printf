/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_operatoins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:12:48 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:13:44 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "big_int.h"

void	big_int_create(t_big_int *big_int)
{
	big_int->size = 0;
}

void	big_int_create_size(t_big_int *big_int, int size)
{
	big_int->size = size;
	while (--size >= 0)
		big_int->digits[size] = 0;
}

int		big_int_back(const t_big_int *big_int)
{
	return (big_int->digits[big_int->size - 1]);
}

void	big_int_push_back(t_big_int *big_int, int val)
{
	if (big_int->size == BIGINT_SIZE)
		exit(1);
	else
		big_int->digits[big_int->size++] = val;
}

void	big_int_pop_back(t_big_int *big_int)
{
	if (big_int->size == 0)
		exit(1);
	else
		--big_int->size;
}
