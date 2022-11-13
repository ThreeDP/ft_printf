/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/13 11:54:42 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_typechar  *formatchar(char c)
{
    t_typechar  *format;
    
    format = malloc(sizeof(t_typechar));
    if (!format)
        return (NULL);
    format->value = c;
    return (format);
}

int printchar(int fd, char c, t_list **lst)
{
    int bsr;
    
    (*lst)->arg = formatchar(c);
    bsr = ft_putchar_fd(((t_typechar *)(*lst)->arg)->value, fd);
    ft_lstadd_back(lst, ft_lstnew('\0', NULL));
    return (bsr);
}

t_typestring    *formatstring(char *str)
{
    t_typestring    *format;

    format = malloc(sizeof(t_typechar));
    if (!format)
        return (NULL);
    format->value = ft_strdup(str);
    if (!format->value)
        return (free(format), NULL);
    return (format);
}

int printstring(int fd, char *str, t_list **lst)
{
    int bsr;
    
    (*lst)->arg = formatstring(str);
    bsr = ft_putstr_fd(((t_typestring *)(*lst)->arg)->value, fd);
    ft_lstadd_back(lst, ft_lstnew('\0', NULL));
    return bsr;
}