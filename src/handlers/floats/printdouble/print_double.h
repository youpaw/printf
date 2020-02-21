/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:34:34 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/21 15:42:16 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DOUBLE_H
# define PRINT_DOUBLE_H

# include "double_unpacked.h"

typedef struct
{
	int			total_width;
	int			fractional_width;
	int			left_align;
	int			big_f;
}				t_double_options;

char			*print_double(long double d, t_double_options *options);

#endif
