/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int_arithmetics.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:12:52 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:10:00 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "big_int.h"
#include "utils.h"

void	big_int_add(t_big_int *a, const t_big_int *b)
{
	int		carry;
	size_t	i;

	carry = 0;
	i = 0;
	while (i < my_max(a->size, b->size) || carry)
	{
		if (i == a->size)
			big_int_push_back(a, 0);
		a->digits[i] += carry + (i < b->size ? b->digits[i] : 0);
		carry = a->digits[i] >= BIGINT_BASE;
		if (carry)
			a->digits[i] -= BIGINT_BASE;
		++i;
	}
}

void	big_int_multiply(t_big_int *a, int b)
{
	int			carry;
	size_t		i;
	long long	cur;

	carry = 0;
	i = 0;
	while (i < a->size || carry)
	{
		if (i == a->size)
			big_int_push_back(a, 0);
		cur = carry + a->digits[i] * 1ll * b;
		a->digits[i] = (int)(cur % BIGINT_BASE);
		carry = (int)(cur / BIGINT_BASE);
		++i;
	}
	while (a->size > 1 && (big_int_back(a) == 0))
		big_int_pop_back(a);
}

void	big_int_multiply_big(t_big_int *c, const t_big_int *a,
		const t_big_int *b)
{
	size_t		i;
	size_t		j;
	int			carry;
	long long	cur;

	big_int_create_size(c, a->size + b->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		carry = 0;
		while (j < b->size || carry)
		{
			cur = c->digits[i + j] + a->digits[i] * 1ll *
				(j < b->size ? b->digits[j] : 0) + carry;
			c->digits[i + j] = (int)(cur % BIGINT_BASE);
			carry = (int)(cur / BIGINT_BASE);
			++j;
		}
		++i;
	}
	while (c->size > 1 && big_int_back(c) == 0)
		big_int_pop_back(c);
}

void	n_pow_y(t_big_int *big_int_result, int n, int y)
{
	big_int_result->size = 0;
	big_int_push_back(big_int_result, n);
	while (--y > 0)
	{
		big_int_multiply(big_int_result, n);
	}
}

void	big_int_divide(t_big_int *a, int b)
{
	int			carry;
	int			i;
	long long	cur;

	carry = 0;
	i = (int)a->size - 1;
	while (i >= 0)
	{
		cur = a->digits[i] + carry * 1ll * BIGINT_BASE;
		a->digits[i] = (int)(cur / b);
		carry = (int)(cur % b);
		--i;
	}
	while (a->size > 1 && big_int_back(a) == 0)
		big_int_pop_back(a);
}
