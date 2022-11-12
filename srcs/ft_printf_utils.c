/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/12 20:20:36 by dapaulin         ###   ########.fr       */
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

int printchar(char c, t_list ** lst)
{
    int bsr;
    
    lst->arg = formatchar(c);
    bsr = ft_putchar_fd(((t_typechar *)lst->arg)->value, fd);
    cached_str++;
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