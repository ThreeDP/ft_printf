/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:31:00 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/06 19:17:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_strchr(const char *str, int c)
{
	size_t	i;
	char	cached_c;

	i = 0;
	cached_c = (char)c;
	while (str[i] && str[i] != cached_c)
		i++;
	if (str[i] == cached_c)
		return (&((char *)str)[i]);
	return (0);
}

char	*get_strdup(const char *s, size_t size)
{
	char	*ptr;

	ptr = (char *) malloc(size * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, size + 1);
	return (ptr);
}

t_getlist	*get_lstnew(char *content)
{
	t_getlist	*head;

	head = malloc(sizeof(t_getlist));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}

void	get_lstadd_back(t_getlist **lst, t_getlist *new)
{
	t_getlist	*tail;
	t_getlist	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	while (head)
	{
		tail = head;
		head = head->next;
	}
	if (tail == NULL)
		*lst = new;
	else
		tail -> next = new;
}

void	get_lstclear(t_getlist **lst, void (*del)(void *))
{
	t_getlist	*head;
	t_getlist	*next;

	head = *lst;
	next = *lst;
	while (next)
	{
		head = head -> next;
		del(next -> content);
		free(next);
		next = head;
	}
	*lst = NULL;
}
