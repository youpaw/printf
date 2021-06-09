/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 22:28:37 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/05 19:30:52 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"

int	ft_handle_hex(t_params *params, va_list args)
{
	char	*res;

	res = ft_itoabase(ft_util_usize(args, params->size), 16, params->type);
	if (params->rigor && params->flags[3] && *res != '0')
		ft_util_hexpref(&res, params->type);
	else
		params->flags[3] = 0;
	ft_util_rigor(&res, params, params->flags[3] * 2);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
