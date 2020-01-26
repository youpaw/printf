/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:06:12 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:02 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	if (!*haystack && !*needle)
		return ((char*)(haystack));
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[j])
		{
			j++;
			i++;
		}
		if (!needle[i])
			return ((char*)(haystack + j - i));
		j = j - i + 1;
	}
	return (NULL);
}
