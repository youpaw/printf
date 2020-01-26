/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 05:37:09 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:03 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntdwords(const char *s, char c)
{
	size_t words;
	size_t i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static void		ft_freewords(char ***arr, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_strdel((*arr) + i);
		i++;
	}
	if (*arr)
		free(*arr);
	*arr = NULL;
}

static char		**ft_getdwords(char **arr, const char *s, char c)
{
	size_t i;
	size_t j;
	size_t len;

	len = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			len++;
		else if (len)
		{
			if (!(arr[j] = ft_strsub(s, i - len, len)))
				break ;
			j++;
			len = 0;
		}
		i++;
	}
	if (s[i] || !(arr[j] = ft_strsub(s, i - len, len)))
		return (NULL);
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	wrdcnt;
	char	**sp;

	if (!s)
		return (NULL);
	wrdcnt = ft_cntdwords(s, c);
	if (wrdcnt + 1 == 0)
		return (NULL);
	if (!(sp = (char**)malloc(sizeof(char*) * wrdcnt + 1)))
		return (NULL);
	if (!(sp = ft_getdwords(sp, s, c)))
		ft_freewords(&sp, wrdcnt + 1);
	else
		sp[wrdcnt] = NULL;
	return (sp);
}
