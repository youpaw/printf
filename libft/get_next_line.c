/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:25:30 by dbutterw          #+#    #+#             */
/*   Updated: 2019/09/17 19:16:52 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_del(void *content, size_t fd)
{
	if (content)
		free(content);
	if (fd)
		return ;
}

static	void	ft_lstdel_fd(t_list **lst, size_t fd)
{
	t_list *head;
	t_list *prev;
	t_list *next;

	head = *lst;
	prev = NULL;
	if (!head->next)
		return (ft_lstdelone(lst, &ft_del));
	while (head->content_size != fd)
	{
		prev = head;
		head = head->next;
	}
	next = head->next;
	ft_lstdelone(&head, &ft_del);
	if (prev)
	{
		prev->next = next;
		*lst = prev;
	}
	else
		*lst = next;
}

static t_list	*ft_find_fd(t_list **lst, size_t fd)
{
	t_list *head;

	head = *lst;
	while (head && head->content_size != fd)
		head = head->next;
	if (head)
		return (head);
	if (!(head = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	head->content = NULL;
	head->content_size = fd;
	head->next = NULL;
	ft_lstadd(lst, head);
	return (*lst);
}

static int		ft_readline(t_list *tmp, char **line, char *buff, int fd)
{
	char	*str;
	char	*ptr;
	size_t	size;

	size = 1;
	while (size > 0)
	{
		if ((str = ft_strchr(tmp->content, '\n')))
			*str++ = '\0';
		ptr = ft_strjoin(*line, (char*)tmp->content);
		free(*line);
		*line = ptr;
		if (!ptr || (str && !(str = ft_strdup(str))))
			return (-1);
		free(tmp->content);
		tmp->content = str;
		if (str)
			return (1);
		size = read(fd, buff, BUFF_SIZE);
		if (!size && ft_strlen(*line))
			return (1);
		tmp->content = ft_strsub(buff, 0, size);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*lst;
	t_list				*tmp;
	char				buff[BUFF_SIZE + 1];
	int					rd;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(tmp = ft_find_fd(&lst, (size_t)fd)))
		return (-1);
	if (!tmp->content)
		if (!(tmp->content = ft_strnew(0)))
			return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if ((rd = ft_readline(tmp, line, buff, fd)) <= 0)
		ft_lstdel_fd(&lst, fd);
	return (rd);
}
