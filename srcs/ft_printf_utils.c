/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/13 19:21:10 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

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
    return (bsr);
}

t_typeint   *formatint(int integer)
{
    t_typeint       *format;

    format = malloc(sizeof(t_typeint));
    if (!format)
        return NULL;
    if (integer < 0)
    {
        format->signal = '-';
        format->value = integer * -1;
    }
    else
    {
        format->signal = '+';
        format->value = integer * 1;
    }
    return (format);
}

int printinteger(int fd, int integer, t_list **lst)
{
    int bsr;

    bsr = 0;
    (*lst)->arg = formatint(integer);
    if (((t_typeint *)(*lst)->arg)->signal == '-')
        bsr += ft_putchar_fd('-', fd);
    ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
    ft_lstadd_back(lst, ft_lstnew('\0', NULL));
    return (bsr);
}

int printuinteger(int fd, int uinteger, t_list **lst)
{
    int bsr;

    bsr = 0;
    (*lst)->arg = formatint(uinteger);
    ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
    ft_lstadd_back(lst, ft_lstnew('\0', NULL));
    return (bsr);
}

t_typehex  *formathex(unsigned int num)
{
    t_typehex  *format;
    
    format = malloc(sizeof(t_typehex));
    if (!format)
        return (NULL);
    format->value = num;
    return (format);
}

int printhex(int fd, unsigned int num, t_list **lst)
{
    int bsr;

    bsr = 0;
    (*lst)->arg = formathex(num);
    if ((*lst)->type == 'x')
        ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, L_BHEX);
    else if ((*lst)->type == 'X')
        ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, U_BHEX);
    ft_lstadd_back(lst, ft_lstnew('\0', NULL));
    return (bsr);
}