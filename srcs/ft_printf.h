/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:37 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/13 15:04:48 by dapaulin         ###   ########.fr       */
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

typedef struct
{
    char            signal;
    unsigned int    value;
}   t_typeint;

// PRINCIPAL FUNCTION 
int                 ft_printf(int fd, const char *str, ...);
// FORMAT FUNCTIONS
t_typechar          *formatchar(char c);
t_typestring        *formatstring(char *str);
t_typeint           *formatint(int integer);
// PRINT FUNCTIONS
int                 printchar(int fd, char c, t_list **lst);
int                 printstring(int fd, char *str, t_list **lst);
int                 printinteger(int fd, int integer, t_list **lst);
int                 printuinteger(int fd, int uinteger, t_list **lst);
#endif