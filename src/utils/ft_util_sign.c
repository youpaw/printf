/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:40:39 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/02 22:40:39 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_util_sign(char **res, const short *flags)
{
	char *tmp;

	if (!res || !*res)
		return ;
	if (**res != '-' && (flags[1] || flags[2]))
	{
		if ((tmp = ft_strjoin(" ", *res)) && flags[1])
			*tmp = '+';
		free(*res);
		*res = tmp;
	}
}
