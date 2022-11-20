/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/19 21:02:00 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	printchar(int fd, char c, t_format **shape)
{
	int	bsr;

    
	(*shape)->arg = formatchar(c);
	bsr = ft_putchar_fd(((t_typechar *)(*shape)->arg)->value, fd);
	return (bsr);
}

int	printf_formatstring(int fd, t_typestring **format)
{
	int bsr;

	bsr = 0;
	while ((*format)->bytes > 0)
	{
		bsr += ft_putchar(' ', fd);
		(*format)->bytes--;
	}
	bsr += ft_putstr_fd((*format)->value, fd);
}

int	printstring(int fd, char *str, t_format **shape)
{
	int	bsr;

	bsr = 0;
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	(*shape)->arg = formatstring(str, (*shape)->flags);
	bsr += printf_formatstring(fd, (t_typestring *)(*shape)->arg);
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