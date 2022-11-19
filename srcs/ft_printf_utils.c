/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/19 19:31:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	printchar(int fd, char c, t_list **lst)
{
	int	bsr;

    
	(*lst)->arg = formatchar(c);
	bsr = ft_putchar_fd(((t_typechar *)(*lst)->arg)->value, fd);
	return (bsr);
}

int	printstring(int fd, char *str, t_list **lst)
{
	int	bsr;

	if (!str)
		return (ft_putstr_fd("(null)", fd));
	(*lst)->arg = formatstring(str, "");
	bsr = ft_putstr_fd(((t_typestring *)(*lst)->arg)->value, fd);
	return (bsr);
}

int	printinteger(int fd, int integer, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formatint(integer);
	if (((t_typeint *)(*lst)->arg)->signal == '-')
		bsr += ft_putchar_fd('-', fd);
	ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
	return (bsr);
}

int	printuinteger(int fd, int uinteger, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formatuint(uinteger);
	ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
	return (bsr);
}

int	printhex(int fd, unsigned int num, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formathex(num);
	if ((*lst)->type == 'x')
		ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, L_BHEX);
	else if ((*lst)->type == 'X')
		ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, U_BHEX);
	return (bsr);
}

int printpointer(int fd, unsigned long num, t_list **lst)
{
	int bsr;

	bsr = 0;
	if (!num)
		return (ft_putstr_fd("(nil)", fd));
	(*lst)->arg = formatpointer(num);
	bsr += ft_putstr_fd("0x", fd);
	ft_putnbrhex_fd(((t_typepointer *)(*lst)->arg)->value, fd, &bsr, L_BHEX);
	return (bsr);
}

/* Função responsavel por validar se uma sub-string é digit 
e retornar um valor do tipo inteito */
int	sub_atoi(const char *strnum, int *size)
{
	int		i;
	char 	*flag;
	int		num;
	
	i = 0;
	num = 0;
	while (ft_isdigit(strnum[i]))
		i++;
	if (i > 0)
	{
		flag = ft_strndup(strnum, i);
		*size += i;
		num = ft_atoi(flag);
		if (!flag)
			free(flag);
	}
	return (num);
}

/* 
Valida se o caracter atual coresponde a flag passada
*/
t_bool	ft_isflag(char flag, char c, int *i)
{
	if (c == flag)
		return (*i+=1, TRUE);
	return (FALSE);
}