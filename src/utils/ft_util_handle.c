/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:36:30 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 21:29:10 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

ssize_t		ft_util_handle(char **format, va_list args)
{
	t_params	*params;
	ssize_t		ret;
	short		i;

	i = 0;
	if (!(params = ft_get_params(format, args)))
		return (0);
	while(i < N_TYPES)
	{
		if (handlers[i].type == params->type)
		{
			ret = handlers[i].handler(params, args);
			free(params);
			return (ret);
		}
		i++;
	}
	ret = ft_handle_nul(params);
	free(params);
	return (ret);
}
