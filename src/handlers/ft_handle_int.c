/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:03:42 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:18:52 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_handle_int(t_params *params, va_list args)
{
	char	*res;

	res = ft_itoa(ft_util_size(args, params->size));
	ft_util_sign(&res, params->flags);
	ft_util_rigor(&res, params, !ft_isdigit(*res));
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}