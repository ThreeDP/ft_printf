/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/15 15:37:55 by dapaulin         ###   ########.fr       */
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
	(*lst)->arg = formatstring(str);
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
