/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:37 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/12 20:35:40 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct
{
    char            value;
}   t_typechar;

typedef struct
{
    char            *value;
}   t_typestring;

// PRINCIPAL FUNCTION 
int                 ft_printf(int fd, const char *str, ...);
// UTILS
t_typechar          *formatchar(char c);
int                 printchar(int fd, char c, t_list **lst);
t_typestring        *formatstring(char *str);
#endif