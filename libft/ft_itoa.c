/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:16:18 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/05 20:28:20 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(ssize_t n)
{
	int		len;

	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n > 9 || n < -9)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

char		*ft_itoa(ssize_t n)
{
	size_t	t;
	char	*str;
	int		size;

	size = ft_intlen(n);
	if (n < 0)
		t = (size_t)(~n + 1);
	else
		t = (size_t)n;
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (t > 9)
	{
		str[--size] = t % 10 + '0';
		t /= 10;
	}
	str[--size] = t % 10 + '0';
	if (size)
		str[--size] = '-';
	return (str);
}
