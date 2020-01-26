/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:13:22 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 22:45:25 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *format, ...)
{
	va_list args;
	ssize_t ret;

	if (!format)
		return (0);
	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
			ret += ft_util_handle(&format, args);
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