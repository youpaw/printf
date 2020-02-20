/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:28:04 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 16:28:15 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdlib.h>
# include "double_representation.h"

size_t	my_max(size_t a, size_t b);
int		int_decimal_size(int i);
int		to_int(char ch);
int		bit_width(t_double_bit bits);
void	str_shift_left(char *str);

#endif
