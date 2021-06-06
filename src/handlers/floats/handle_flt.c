/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:29:27 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/21 15:38:39 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_double.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char				*res;
	long double			val;
	t_double_options	options;

	val = 0;
	if (params->size == 'L')
		val = va_arg(args, long double);
	else
		val = va_arg(args, double);
	options.total_width = params->width < 0 ? 0 : params->width;
	options.fractional_width = params->rigor < 0 ? 6 : params->rigor;
	options.left_align = params->flags[0];
	options.big_f = params->type == 'F';
	res = print_double(val, &options);
	return (ft_util_print(&res));
}
