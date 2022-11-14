/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:37 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/14 14:25:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define U_BHEX "0123456789ABCDEF"
# define L_BHEX "0123456789abcdef"

typedef struct s_typechar
{
	char	value;
}	t_typechar;

typedef struct s_typestring
{
	char	*value;
}	t_typestring;

typedef struct s_typeint
{
	char			signal;
	unsigned int	value;
}	t_typeint;

typedef struct s_typehex
{
	unsigned int	value;
}	t_typehex;

// PRINCIPAL FUNCTION 
int					ft_printf(int fd, const char *str, ...);
// FORMAT FUNCTIONS
t_typechar			*formatchar(char c);
t_typestring		*formatstring(char *str);
t_typeint			*formatint(int integer);
t_typehex			*formathex(unsigned int num);
// PRINT FUNCTIONS
int					printchar(int fd, char c, t_list **lst);
int					printstring(int fd, char *str, t_list **lst);
int					printinteger(int fd, int integer, t_list **lst);
int					printuinteger(int fd, int uinteger, t_list **lst);
int					printhex(int fd, unsigned int num, t_list **lst);
#endif