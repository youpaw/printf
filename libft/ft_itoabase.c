/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:59:00 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/05 20:28:20 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		ft_basechar(size_t n, char reg)
{
	char		*bchars;

	if (reg == 'x')
		bchars = "0123456789abcdef";
	else
		bchars = "0123456789ABCDEF";
	return (bchars[n]);
}

static int		ft_size(size_t n, size_t base)
{
	int			len;

	len = 0;
	while (n > base - 1)
	{
		len++;
		n /= base;
	}
	return (++len);
}

char			*ft_itoabase(size_t n, size_t base, char reg)
{
	char		*str;
	int			size;

	if (base > 16 || base < 2)
		return (NULL);
	size = ft_size(n, base);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (n > base - 1)
	{
		str[--size] = ft_basechar(n % base, reg);
		n /= base;
	}
	str[--size] = ft_basechar(n % base, reg);
	return (str);
}
