/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:16:26 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t reslen;

	dstlen = ft_strlen(dst);
	reslen = FMIN(dstlen, size) + ft_strlen(src);
	if (size > dstlen)
	{
		dst += dstlen;
		size -= dstlen;
		while (*src && size-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (reslen);
}
