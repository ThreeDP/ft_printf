/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:51:37 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 18:36:45 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/srcs/libft.h"

# define U_BHEX "0123456789ABCDEF"
# define L_BHEX "0123456789abcdef"

typedef enum e_bool
{
	f,
	t
}		t_bool;

typedef struct a_format
{
	char			type;
	int				f_pos;
	char			*flags;
	void			*arg;
}	t_format;

typedef struct s_typechar
{
	t_bool	minus;
	int		bytes;
	char	value;
	int		valid_bytes;
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
	t_bool			space;
	t_bool			plus;
	t_bool			fzero;
	t_bool			minus;
	int				bytes;
	t_bool			dot;
	int				bytes_s;
	unsigned int	value;
	int				valid_bytes;
}	t_typeint;

typedef struct s_typehex
{
	t_bool			minus;
	t_bool			hash;
	t_bool			fzero;
	int				bytes;
	t_bool			dot;
	int				bytes_s;
	int				valid_bytes;
	unsigned int	value;
}	t_typehex;

typedef struct s_typepointer
{
	unsigned long	value;
}	t_typepointer;

// PRINCIPAL FUNCTION 
int				select_type(va_list *args, t_format **shape, int fd);
int				ft_printf(const char *str, ...);
// CREATE FUNCTIONS
t_format		*new_format(void);
t_typechar		*new_typechar(char c);
t_typestring	*new_typestring(char *str);
t_typehex		*new_typehex(unsigned int num);
t_typeint		*new_typeint(unsigned int num, char signal);
// FORMAT FUNCTIONS
t_typechar		*formatchar(char c, const char *flags);
t_typestring	*formatstring(char *str, const char *flags);
t_typeint		*formatint(int integer, const char *flags, char type);
t_typehex		*formathex(unsigned int num, const char *flags);
t_typepointer	*formatpointer(unsigned long num);
// PRINTF FLAGS
int				printf_formatchar(int fd, t_typechar *format);
int				printf_formatstring(int fd, t_typestring *format);
int 			printf_formatint(int fd, t_typeint *format);
int				printf_formathex(int fd, t_typehex *format);
// PRINT FUNCTIONS
int				printchar(int fd, char c, t_format **shape);
int				printstring(int fd, char *str, t_format **shape);
int				printint(int fd, int integer, t_format **shape);
int				printhex(int fd, unsigned int num, t_format **shape);
int				printpointer(int fd, unsigned long num, t_format **shape);
// AUX FUNCTIONS
int				sub_atoi(const char *strnum, int *size);
int				print_spaces(int fd, int *bytes, char symbol);
t_bool			ft_isflag(char flag, char c, int *i);
unsigned int	convert_num(int num, char signal);
int				match_iflags(char *flags, t_bool *f1, t_typeint **format, char flag);
int				match_xflags(char *flags, t_bool *f1, t_bool *f2, char flag);
void			format_iflags(t_typeint **format, int size);
#endif
