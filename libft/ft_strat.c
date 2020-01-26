/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:21:45 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:02 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strat(const char *haystack, const char *needle)
{
	int i;
	int j;

	if (!haystack || !needle)
		return (-1);
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
			return (j - i);
		j = j - i + 1;
	}
	return (-1);
}
