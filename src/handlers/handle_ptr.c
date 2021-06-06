/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:53:16 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/20 16:31:04 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_handle_ptr(t_params *params, va_list args)
{
	char *res;

	params->size = 'z';
	res = ft_itoabase(ft_util_usize(args, params->size), 16, 'x');
	ft_util_hexpref(&res, 'x');
	ft_util_rigor(&res, params, 2);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
