/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:36:25 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:42:48 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*str_create(int size)
{
	char	*str;

	str = (char*)malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	return (str);
}

void	str_fill(char *str, int size, char ch)
{
	int i;

	i = 0;
	while (i < size)
		str[i++] = ch;
}

int		str_len(const char *str)
{
	int size;

	size = 0;
	while (*(str + size))
		++size;
	return (size);
}

void	str_copy(char *dst, const char *src)
{
	while (*dst = *src)
	{
		++dst;
		++src;
	}
}

char	*str_cat(const char *str1, const char *str2)
{
	int		size1;
	int		size2;
	char	*str;

	size1 = str_len(str1);
	size2 = str_len(str2);
	str = str_create(size1 + size2);
	str_copy(str, str1);
	str_copy(str + size1, str2);
	return (str);
}
