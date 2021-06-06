/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_hexpref.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 18:22:45 by dbutterw          #+#    #+#             */
/*   Updated: 2019/10/03 18:43:18 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "string/ft_str.h"

void	ft_util_hexpref(char **res, char type)
{
	char *pref;
	char *tmp;

	if (!res || !*res)
		return ;
	if (!(pref = ft_strnew(2)))
	{
		free(*res);
		*res = NULL;
		return ;
	}
	pref[0] = '0';
	pref[1] = type;
	tmp = ft_strjoin(pref, *res);
	free(*res);
	free(pref);
	*res = tmp;
}
