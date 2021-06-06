/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:42:05 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 15:50:51 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string/ft_str.h"
#include "memory/ft_mem.h"

void	ft_util_width(char **res, int width, short align)
{
	int		len;
	char	*tmp;
	char	*fmt;

	if (!res || !*res || (len = (int) ft_strlen(*res)) >= width)
		return ;
	len = width - len;
	if ((tmp = ft_strnew(len)))
		tmp = ft_memset(tmp, ' ', len);
	if (align)
		fmt = ft_strjoin(*res, tmp);
	else
		fmt = ft_strjoin(tmp, *res);
	free(*res);
	if (tmp)
		free(tmp);
	*res = fmt;
}
