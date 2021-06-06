/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:05:50 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/20 16:32:09 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "string/ft_str.h"
#include "char/ft_char.h"

int		ft_handle_chr(t_params *params, va_list args)
{
	char	*pad;
	char	out;
	int		ret;

	pad = ft_strnew(1);
	out = (char)va_arg(args, int);
	params->width--;
	params->rigor = -1;
	ft_util_rigor(&pad, params, 0);
	ft_util_width(&pad, params->width, params->flags[0]);
	if (params->flags[0])
	{
		ft_putchar(out);
		ret = ft_util_print(&pad) + 1;
	}
	else
	{
		ret = ft_util_print(&pad) + 1;
		ft_putchar(out);
	}
	return (ret);
}
