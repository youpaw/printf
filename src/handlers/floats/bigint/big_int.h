/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:09:11 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 14:10:22 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_INT_H
# define BIG_INT_H

# include <stdint.h>
# include <stdlib.h>
# include "double_representation.h"

# define BIGINT_SIZE 2000
# define BIGINT_BASE 1000000000

typedef struct
{
	int		digits[BIGINT_SIZE];
	size_t	size;
}			t_big_int;

void		big_int_create(t_big_int *big_int);
void		big_int_create_size(t_big_int *big_int, int size);
int			big_int_back(const t_big_int *big_int);
void		big_int_push_back(t_big_int *big_int, int val);
void		big_int_pop_back(t_big_int *big_int);
void		big_int_add(t_big_int *a, const t_big_int *b);
void		big_int_multiply(t_big_int *a, int b);
void		big_int_multiply_big(t_big_int *c, const t_big_int *a,
		const t_big_int *b);
void		n_pow_y(t_big_int *big_int_result, int n, int y);
void		big_int_divide(t_big_int *a, int b);
int			print_to_string_imp(char *buff, int size, int i, int *cur_pos);
int			print_to_string(char *buff, int buff_size, int width, int i);
void		big_int_print(char *buff, int buff_size, const t_big_int
		*big_int, int is_frac);
int			big_int_decimal_size(const t_big_int *bi);
void		big_int_from_int(t_big_int *a, t_double_bit b);

#endif
