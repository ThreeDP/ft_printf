/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:37 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/19 20:12:35 by dapaulin         ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE,
	TRUE
}		t_bool;

typedef struct s_typechar
{
	int		bytes;
	char	value;
}	t_typechar;

typedef struct s_typestring
{
	t_bool	minus;
	int		bytes;
	t_bool	dot;
	int		bytes_s;
	char	*value;
	int		valid_bytes;
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

typedef struct s_typepointer
{
	unsigned long	value;
}	t_typepointer;

// PRINCIPAL FUNCTION 
int					ft_printf(int fd, const char *str, ...);
// CREATE FUNCTIONS
t_typestring		*new_typestring(char *str);
// FORMAT FUNCTIONS
t_typechar			*formatchar(char c);
t_typestring		*formatstring(char *str, const char *flags);
t_typeint			*formatint(int integer);
t_typeint			*formatuint(int uinteger);
t_typehex			*formathex(unsigned int num);
t_typepointer		*formatpointer(unsigned long num);
// PRINT FUNCTIONS
int					printchar(int fd, char c, t_list **lst);
int					printstring(int fd, char *str, t_list **lst);
int					printinteger(int fd, int integer, t_list **lst);
int					printuinteger(int fd, int uinteger, t_list **lst);
int					printhex(int fd, unsigned int num, t_list **lst);
int					printpointer(int fd, unsigned long num, t_list **lst);
// AUX FUNCTIONS
int					sub_atoi(const char *strnum, int *size);
t_bool				ft_isflag(char flag, char c, int *i);
#endif