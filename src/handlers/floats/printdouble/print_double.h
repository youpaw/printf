/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:34:34 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:34:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DOUBLE_H
# define PRINT_DOUBLE_H

# include "double_unpacked.h"

char	*print_double(long double d, int total_width, int fractional_width,
		int left_align);

#endif
