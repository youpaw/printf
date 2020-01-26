/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:26:19 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 19:30:53 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_memchrat(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	t;
	size_t			i;

	ts = (unsigned char *)s;
	t = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ts[i] == t)
			return (i);
		i++;
	}
	return (n);
}
