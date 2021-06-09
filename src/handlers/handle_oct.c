/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:16:46 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/20 16:29:34 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"

int	ft_handle_oct(t_params *params, va_list args)
{
	char	*res;
	char	*tmp;

	res = ft_itoabase(ft_util_usize(args, params->size), 8, 0);
	if (params->flags[3] && *res != '0')
	{
		tmp = ft_strjoin("0", res);
		free(res);
		res = tmp;
		params->rigor--;
	}
	ft_util_rigor(&res, params, params->flags[3]);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
