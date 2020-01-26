/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:03:31 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:02 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sig;
	long long			res;
	long long			tmp;

	sig = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sig = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		tmp = res;
		res = res * 10 + (*str - '0');
		if (tmp != (res - (*str - '0')) / 10 || res < 0)
			return (-1 * (sig + 1) / 2);
		str++;
	}
	return ((int)(res * sig));
}
