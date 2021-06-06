/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:36:30 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 17:40:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

char		to_lower(char ch)
{
	if (ch > 64 && ch < 91)
		return (ch + 32);
	else
		return (ch);
}

ssize_t		ft_util_handle(char **format, va_list args)
{
	t_params	*params;
	ssize_t		ret;
	short		i;

	i = 0;
	if (!(params = ft_get_params(format, args)))
		return (0);
	while (i < N_TYPES)
	{
		if (g_handlers[i].type == to_lower(params->type))
		{
			ret = g_handlers[i].handler(params, args);
			free(params);
			return (ret);
		}
		i++;
	}
	ret = ft_handle_nul(params);
	free(params);
	return (ret);
}
