/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_unpacked.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:17:30 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:21:31 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_UNPACKED_H
# define DOUBLE_UNPACKED_H

# include "big_int.h"

# define DOUBLE_NORMAL 0
# define DOUBLE_INF 1
# define DOUBLE_NAN 2
# define DOUBLE_NAN_SIG 3
# define DOUBLE_NAN_IND 4

/*
** special --> 0 - nothing special
** 1 --> for infinity
** 2 --> for Nan
*/

typedef struct
{
	int			sign;
	t_big_int	integer;
	t_big_int	fractional;
	int			special;
}				t_double_unpacked;

char			*print_double_unpacked_normal(const t_double_unpacked *du,
		int frac_width);
#endif
