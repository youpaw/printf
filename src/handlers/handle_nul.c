/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:29:21 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:29:21 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"

int		ft_handle_nul(t_params *params)
{
	char	*res;
	int		pad;

	if ((res = ft_strnew(1)))
		res[0] = params->type;
	pad = !(params->type);
	ft_util_rigor(&res, params, pad);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}
