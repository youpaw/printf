/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpack_double.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:17:35 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:57:46 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNPACK_DOUBLE_H
# define UNPACK_DOUBLE_H

# include "double_unpacked.h"

t_double_unpacked	unpack_double(long double d);
void				calc_fractional(t_big_int *fractional, t_double_bit fract,
		int initial_pow, int denormal);
void				unpack_below_one(t_big_int *integer,
		t_big_int *fractional, uint32_t e, t_double_bit m);
void				unpack_average(t_big_int *integer, t_big_int *fractional,
		uint32_t e, t_double_bit m);
void				unpack_huge(t_big_int *integer, t_big_int *fractional,
		uint32_t e, t_double_bit m);

#endif
