/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:03:42 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/20 16:31:19 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"
#include "char/ft_char.h"

int		ft_handle_int(t_params *params, va_list args)
{
	char	*res;

	res = ft_itoa(ft_util_size(args, params->size));
	ft_util_sign(&res, params->flags);
	ft_util_rigor(&res, params, !ft_isdigit(*res));
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
