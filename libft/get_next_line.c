/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:39:51 by ggrybova          #+#    #+#             */
/*   Updated: 2017/08/21 19:03:07 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*find_fd(t_list **head, const int fd)
{
	t_list			*tmp;
	t_list			*lst;

	tmp = *head;
	while (tmp)
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		else
			tmp = tmp->next;
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = ft_strnew(0);
	tmp->content_size = (size_t)fd;
	tmp->next = NULL;
	if (!(*head))
	{
		*head = tmp;
		return (tmp);
	}
	lst = *head;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	return (tmp);
}

int				fillrest(t_list *tmp, char *buf, char **line)
{
	char			*str;
	char			*tmp_str;

	tmp_str = ft_strjoin(tmp->content, buf);
	free(tmp->content);
	str = ft_strchr(tmp_str, 10);
	if (str == NULL)
	{
		tmp->content = tmp_str;
		ft_bzero(buf, BUFF_SIZE);
		return (0);
	}
	free(*line);
	*line = ft_strsub(tmp_str, 0, (str - tmp_str));
	tmp->content = ft_strdup(str + 1);
	ft_bzero(buf, BUFF_SIZE);
	free(tmp_str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || (read(fd, buf, 0) < 0))
		return (-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	tmp = find_fd(&head, fd);
	while (read((int)(tmp->content_size), buf, BUFF_SIZE) > 0)
		if (fillrest(tmp, buf, line) == 1)
			return (1);
	if (read((int)(tmp->content_size), buf, BUFF_SIZE) == 0
		&& ft_strlen(tmp->content) > 0)
	{
		if (fillrest(tmp, buf, line) == 1)
			return (1);
		free(*line);
		*line = ft_strdup(tmp->content);
		ft_memset(tmp->content, 0, ft_strlen(tmp->content));
		return (1);
	}
	if (read((int)(tmp->content_size), buf, BUFF_SIZE) == 0 && *line[0] == '\0')
		return (0);
	return (-1);
}
