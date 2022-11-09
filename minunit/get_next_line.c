/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:47:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/07 16:23:27 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	while (i < (size -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

/*
Copy the structure data to a single array
and return the line.						*/
static char	*create_line(t_list **lst, size_t line_size)
{
	char	*line;
	t_list	*list;
	size_t	i;
	size_t	len_line;

	list = *lst;
	line = (char *) malloc(line_size * sizeof(char) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < (line_size + 1) * sizeof(char))
		line[i++] = '\0';
	while (list)
	{
		i = 0;
		len_line = ft_strlen(line);
		if ((line_size + 1) <= len_line)
			break ;
		while ((list-> content)[i] && (len_line + 1) < (line_size + 1))
			line[len_line++] = (list-> content)[i++];
		line[len_line] = '\0';
		list = list-> next;
	}
	return (line);
}

/*
Populate and create new nodes with characters from
the file while not finding a \n character or the
end of the file			*/
static size_t	make_pieces(int fd, char *buffer, t_list **lst, size_t bsr)
{
	size_t	line_size;
	char	*c_pos;
	char	tmp[BUFFER_SIZE];

	line_size = 0;
	while (1)
	{
		c_pos = ft_strchr(buffer, '\n');
		if (c_pos)
		{
			(*lst)->content = ft_strdup(buffer, (c_pos - buffer) + 1);
			ft_strlcpy(tmp, &buffer[(c_pos - buffer) + 1], BUFFER_SIZE);
			ft_strlcpy(buffer, tmp, ft_strlen(tmp) + 1);
			return (line_size += (c_pos - buffer) + 1);
		}
		line_size += bsr;
		(*lst)->content = ft_strdup(buffer, bsr);
		bsr = read(fd, buffer, BUFFER_SIZE);
		buffer[bsr] = '\0';
		if (!bsr)
			return (line_size);
		ft_lstadd_back(lst, ft_lstnew(NULL));
		(*lst) = (*lst)->next;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	t_list		*lst;
	t_list		*ret;
	char		*line;
	size_t		bsr;
	static char	buffer[BUFFER_SIZE];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	lst = ft_lstnew(NULL);
	if (!lst)
		return (NULL);
	ret = lst;
	if (!ft_strlen(buffer))
	{
		bsr = read(fd, buffer, BUFFER_SIZE);
		buffer[bsr] = '\0';
	}
	else
		bsr = ft_strlen(buffer);
	bsr = make_pieces(fd, buffer, &lst, bsr);
	if (bsr)
		line = create_line(&ret, bsr);
	ft_lstclear(&ret, free);
	return (line);
}
