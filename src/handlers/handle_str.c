/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:24:02 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/20 16:30:39 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"
#include "math/ft_math.h"

int		ft_handle_str(t_params *params, va_list args)
{
	size_t	len;
	char	*res;

	if (!(res = va_arg(args, char*)))
		res = "(null)";
	len = ft_min((int64_t)ft_strlen(res), params->rigor);
	res = ft_strsub(res, 0, len);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
