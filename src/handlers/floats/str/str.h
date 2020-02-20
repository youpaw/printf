/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapryl <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:43:34 by mapryl            #+#    #+#             */
/*   Updated: 2020/02/20 15:44:22 by mapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

char	*str_create(int size);
void	str_fill(char *str, int size, char ch);
int		str_len(const char *str);
void	str_copy(char *dst, const char *src);
char	*str_cat(const char *str1, const char *str2);

#endif
