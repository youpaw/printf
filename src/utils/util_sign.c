/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:40:39 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 15:50:37 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string/ft_str.h"

void	ft_util_sign(char **res, const short *flags)
{
	char	*tmp;

	if (!res || !*res)
		return ;
	if (**res != '-' && (flags[1] || flags[2]))
	{
		tmp = ft_strjoin(" ", *res);
		if (flags[1])
			*tmp = '+';
		free(*res);
		*res = tmp;
	}
}
