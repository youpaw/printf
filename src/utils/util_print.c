/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:19:01 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:19:01 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t		ft_util_print(char **res)
{
	ssize_t ret;

	ret = ft_putstr(*res);
	if (*res)
		free(*res);
	return (ret);
}
