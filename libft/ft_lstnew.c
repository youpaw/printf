/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:29:37 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/11 13:57:02 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlst;

	if ((newlst = (t_list*)ft_memalloc(sizeof(t_list))))
	{
		if (!content)
		{
			newlst->content = NULL;
			newlst->content_size = 0;
		}
		else if ((newlst->content = ft_memalloc(content_size)))
		{
			newlst->content = ft_memcpy(newlst->content, content, content_size);
			newlst->content_size = content_size;
		}
		else
		{
			free(newlst);
			return (NULL);
		}
		newlst->next = NULL;
	}
	else
		return (NULL);
	return (newlst);
}
