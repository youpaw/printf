/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:13:22 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 15:36:28 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "char/ft_char.h"

static int	handle_format(const char **format, va_list args)
{
	static const t_handlers	handlers[N_TYPES] =
	{
		{'d', &ft_handle_int}, {'i', &ft_handle_int},
		{'o', &ft_handle_oct}, {'u', &ft_handle_uns},
		{'x', &ft_handle_hex}, {'X', &ft_handle_hex},
		{'c', &ft_handle_chr}, {'s', &ft_handle_str},
		{'p', &ft_handle_ptr}, {'f', &ft_handle_flt}
	};
	t_params				params;
	int						ret;
	short					i;

	i = 0;
	ft_get_params(format, &params, args);
	while (i < N_TYPES)
	{
		if (handlers[i].type == ft_tolower(params.type))
		{
			ret = handlers[i].handler(&params, args);
			return (ret);
		}
		i++;
	}
	ret = ft_handle_nul(&params);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	if (!format)
		return (0);
	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
			ret += handle_format(&format, args);
		else
		{
			ft_putchar(*format++);
			ret++;
		}
		if (ret < 0)
			break ;
	}
	va_end(args);
	return (ret);
}
