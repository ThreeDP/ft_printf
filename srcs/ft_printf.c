/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/11 21:01:16 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int ft_istype(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'X')
        return (1);
    else if ( c == 'd' || c == 'i' || c == 'u' || c == 'x')
        return (1);
    return (0);
}

int ft_printf(int fd, const char *str, ...)
{
    va_list ap;
    int     ret;
    char    *percent;
    char    *str_p;
    int     pc;

    ret = 0;
    va_start(ap, str);
    str_p = (char *)str;
    percent = ft_strchr(str_p, '%');
    if (!percent)
        return (ft_putstr_fd(str_p, fd));
    while (percent)
    {
        ret += write(fd, str_p, (percent - str_p));
        str_p += (percent - str_p) + 1;
        if (ft_istype(*str_p))
        {
            if (*str_p == 'c')
            {
                pc = va_arg(ap, int);
                ft_putchar_fd(pc, fd);
                str_p++;
                ret++;
            }
        }
        percent = ft_strchr(str_p, '%');
    }
    va_end(ap);
    return (ret);
}