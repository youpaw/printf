/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:29:27 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:30:12 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "print_double.h"

ssize_t		ft_handle_flt(t_params *params, va_list args)
{
	char		*res;
	long double	val;

	val = 0;
	if (params->type == 'f' && params->size == 0)
		val = va_arg(args, double);
	if (params->type == 'f' && params->size == 'L')
		val = va_arg(args, long double);
	res = print_double(val, params->width < 0 ? 0 : params->width,
			params->rigor < 0 ? 6 : params->rigor, params->flags[0]);
	return (ft_util_print(&res));
}
