/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:41:26 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/05 19:48:18 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

ssize_t	ft_util_size(va_list args, char size)
{
	ssize_t value;

	if (size == 'l')
		value = va_arg(args, long);
	else if (size == -'h')
		value = (char)va_arg(args, int);
	else if (size == 'h')
		value = (short)va_arg(args, int);
	else if (size == -'l')
		value = va_arg(args, long long);
	else if (size == 'j')
		value = va_arg(args, intmax_t);
	else if (size == 'z')
		value = va_arg(args, ssize_t);
	else if (size == 't')
		value = va_arg(args, ptrdiff_t);
	else if (size == 'L')
		value = va_arg(args, __int64_t);
	else
		value = va_arg(args, int);
	return (value);
}

size_t	ft_util_usize(va_list args, char size)
{
	size_t	value;

	if (size == 'l')
		value = va_arg(args, unsigned long);
	else if (size == -'h')
		value = (unsigned char)va_arg(args, unsigned int);
	else if (size == 'h')
		value = (unsigned short)va_arg(args, unsigned int);
	else if (size == -'l')
		value = va_arg(args, unsigned long long);
	else if (size == 'j')
		value = va_arg(args, uintmax_t);
	else if (size == 'z')
		value = va_arg(args, size_t);
	else if (size == 't')
		value = va_arg(args, size_t);
	else if (size == 'L')
		value = va_arg(args,u_int64_t);
	else
		value = va_arg(args, unsigned int);
	return (value);
}
