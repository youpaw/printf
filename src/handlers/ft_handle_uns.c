/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 21:19:40 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/05 20:31:15 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_handle_uns(t_params *params, va_list args)
{
	char	*res;

	res = ft_itoabase(ft_util_usize(args, params->size), 10, 0);
	ft_util_rigor(&res, params, 0);
	ft_util_width(&res, params->width, params->flags[0]);
	return (ft_util_print(&res));
}