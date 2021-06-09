/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_rigor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:40:12 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 17:35:04 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "string/ft_str.h"
#include "memory/ft_mem.h"
#include "math/ft_math.h"

void	ft_util_rigor(char **res, t_params *params, int pad)
{
	int		len;
	char	*tmp;

	if (!params->rigor && *(*res + pad) == '0')
		*(*res + pad) = 0;
	if (params->flags[4] && !params->flags[0])
	{
		params->rigor = (int) ft_max(params->rigor, params->width) - pad;
		params->width = -1;
	}
	len = (int) ft_strlen(*res) - pad;
	if (len >= params->rigor)
		return ;
	tmp = ft_strnew(params->rigor + pad);
	len = params->rigor - len + pad;
	ft_memset(tmp, '0', len);
	tmp = ft_strcat(tmp, *res + pad);
	while (pad--)
		tmp[pad] = (*res)[pad];
	free(*res);
	*res = tmp;
}
