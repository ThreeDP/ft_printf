/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/28 18:44:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printchar(int fd, char c, t_format **shape)
{
	int	bsr;

    
	(*shape)->arg = formatchar(c);
	bsr = ft_putchar_fd(((t_typechar *)(*shape)->arg)->value, fd);
	return (bsr);
}

int	printf_formatstring(int fd, t_typestring *format)
{
	int bsr;
	int	size;

	bsr = 0;
	size = ft_strlen(format->value);
	if ((!format->bytes_s && !format->dot) || size <= format->bytes_s)
		format->bytes -= size;
	else
	{
		format->bytes -= format->bytes_s;
		size = format->bytes_s;
	}
	if (!format->minus)
		bsr += print_spaces(fd, &format->bytes);
	bsr += write(fd, format->value, size);
	
	bsr += print_spaces(fd, &format->bytes);
	return (bsr);
}

int	printstring(int fd, char *str, t_format **shape)
{
	int	bsr;

	bsr = 0;
	(*shape)->arg = formatstring(str, (*shape)->flags);
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	if (!ft_strlen((*shape)->flags))
		return (ft_putstr_fd(((t_typestring *)(*shape)->arg)->value, fd));
	bsr += printf_formatstring(fd, (*shape)->arg);
	return (bsr);
}

int	printinteger(int fd, int integer, t_format **shape)
{
	int	bsr;

	bsr = 0;
	(*shape)->arg = formatint(integer);
	if (((t_typeint *)(*shape)->arg)->signal == '-')
		bsr += ft_putchar_fd('-', fd);
	ft_putnbr_fd(((t_typeint *)(*shape)->arg)->value, fd, &bsr);
	return (bsr);
}

int	printuinteger(int fd, int uinteger, t_format **shape)
{
	int	bsr;

	bsr = 0;
	(*shape)->arg = formatuint(uinteger);
	ft_putnbr_fd(((t_typeint *)(*shape)->arg)->value, fd, &bsr);
	return (bsr);
}

int	printhex(int fd, unsigned int num, t_format **shape)
{
	int	bsr;

	bsr = 0;
	(*shape)->arg = formathex(num);
	if ((*shape)->type == 'x')
		ft_putnbrhex_fd(((t_typehex *)(*shape)->arg)->value, fd, &bsr, L_BHEX);
	else if ((*shape)->type == 'X')
		ft_putnbrhex_fd(((t_typehex *)(*shape)->arg)->value, fd, &bsr, U_BHEX);
	return (bsr);
}

int printpointer(int fd, unsigned long num, t_format **shape)
{
	int bsr;

	bsr = 0;
	if (!num)
		return (ft_putstr_fd("(nil)", fd));
	(*shape)->arg = formatpointer(num);
	bsr += ft_putstr_fd("0x", fd);
	ft_putnbrhex_fd(((t_typepointer *)(*shape)->arg)->value, fd, &bsr, L_BHEX);
	return (bsr);
}