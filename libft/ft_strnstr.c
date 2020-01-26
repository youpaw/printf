/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:15:30 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t nlen;

	if (!(nlen = ft_strlen(needle)))
		return ((char *)haystack);
	if (ft_strlen(haystack) < nlen || len < nlen)
		return (NULL);
	j = 0;
	while (haystack[j] && j <= len - nlen)
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[j + i])
			i++;
		if (i == nlen)
			return ((char*)(haystack + j));
		j++;
	}
	return (NULL);
}
