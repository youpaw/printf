/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_representation.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:53:17 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 17:01:01 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DOUBLE_REPRESENTATION_H
# define FT_PRINTF_DOUBLE_REPRESENTATION_H

# include <stdint.h>

# define EXPONENT_SIZE_BITS 15
# define MANTISS_SIZE_BITS 64
# define EXPONENT_BIAS 16383
# define IMAGINARY_BIT_PRESENT 1
# define UNDERLYING_TYPE_SIZE 128
# define DOUBLE_SIZE 80
# define LEFT_SHIFT_BITS 48

typedef unsigned int	t_double_bit;
typedef union			u_double_view
{
	long double			ld;
	t_double_bit		view;
}						t_double_view;

t_double_bit			mantiss(t_double_bit d);
uint32_t				exponent(t_double_bit d);
int						msb(t_double_bit d);
t_double_bit			add_imaginary_bit(t_double_bit d);
int						sign(t_double_bit d);
t_double_bit			get_representation(long double d);
t_double_bit			representation_mask();
int						is_zero(t_double_bit d);
int						is_denormal(t_double_bit d);
int						is_inf(t_double_bit d);
int						is_nan_sig(t_double_bit d);
int						is_ind(t_double_bit d);
int						is_nan(t_double_bit d);

#endif
