/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:23:32 by dbutterw          #+#    #+#             */
/*   Updated: 2020/02/21 15:37:43 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "char/ft_char.h"
#include "num/ft_num.h"

static void		ft_get_flags(short *flags, char **format)
{
	short	i;

	i = 0;
	while (i < N_FLAGS)
		flags[i++] = 0;
	while (1)
	{
		i = 0;
		while (i < N_FLAGS && FLAGS[i] != **format)
			i++;
		if (i >= N_FLAGS)
			return ;
		flags[i] = 1;
		(*format)++;
	}
}

static int		ft_get_width(char **params, va_list args)
{
	int ret;

	if (**params == '*')
	{
		(*params)++;
		ret = va_arg(args, int);
		if (**params == '*' || ft_isdigit(**params))
			return (ft_get_width(params, args));
	}
	else if (ft_isdigit(**params))
	{
		ret = ft_atoi(*params);
		while (ft_isdigit(**params))
			(*params)++;
	}
	else
		ret = 0;
	return (ret);
}

static int		ft_get_rigor(char **params, va_list args)
{
	int ret;

	ret = -1;
	if (**params == '.')
	{
		(*params)++;
		ret = 0;
	}
	if (**params == '*')
	{
		(*params)++;
		ret = va_arg(args, int);
		if (**params == '*' || ft_isdigit(**params))
			return (ft_get_rigor(params, args));
	}
	else if (ft_isdigit(**params))
	{
		ret = ft_atoi(*params);
		while (ft_isdigit(**params))
			(*params)++;
	}
	return (ret);
}

static char		ft_get_size(char **params)
{
	char res;
	char *sflags;

	sflags = "lhjztL";
	while (*sflags)
	{
		if (**params == *sflags)
		{
			res = *(*params)++;
			if (**params == res)
			{
				res *= -1;
				(*params)++;
			}
			return (res);
		}
		sflags++;
	}
	return (0);
}

void ft_get_params(char **format, t_params *params, va_list args)
{
	ft_get_flags(params->flags, format);
	params->width = ft_get_width(format, args);
	if (params->width < 0)
	{
		params->width *= -1;
		params->flags[0] = 1;
	}
	params->rigor = ft_get_rigor(format, args);
	if (params->rigor >= 0)
		params->flags[4] = 0;
	params->size = ft_get_size(format);
	params->type = **format;
	if (**format)
		(*format)++;
}
