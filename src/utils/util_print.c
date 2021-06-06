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

#include <stdlib.h>
#include "string/ft_str.h"

int ft_util_print(char **res)
{
	int ret;

	ret = ft_puts(*res);
	if (*res)
		free(*res);
	return (ret);
}
