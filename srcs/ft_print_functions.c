/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 18:34:55 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(int fd, char c, t_format **shape)
{
	(*shape)->arg = formatchar(c, (*shape)->flags);
	if (!(*shape)->arg)
		return (0);
	if (!ft_strlen((*shape)->flags))
		return (ft_putchar_fd(((t_typechar *)(*shape)->arg)->value, fd));
	return (printf_formatchar(fd, (*shape)->arg));
}

int	printstring(int fd, char *str, t_format **shape)
{
	(*shape)->arg = formatstring(str, (*shape)->flags);
	if (!(*shape)->arg)
		return (0);
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	if (!ft_strlen((*shape)->flags))
		return (ft_putstr_fd(((t_typestring *)(*shape)->arg)->value, fd));
	return (printf_formatstring(fd, (*shape)->arg));
}

int	printint(int fd, int integer, t_format **shape)
{
	int bsr;

	bsr = 0;
	(*shape)->arg = formatint(integer, (*shape)->flags, (*shape)->type);
	if (!(*shape)->arg)
		return (0);
	if (!ft_strlen((*shape)->flags))
	{
		if (((t_typeint *)(*shape)->arg)->signal == '-' && (*shape)->type != 'u')
			bsr += ft_putchar_fd('-', fd);
		ft_putnbr_fd(((t_typeint *)(*shape)->arg)->value, fd, &bsr);
		return (bsr);
	}
	return (printf_formatint(fd, (*shape)->arg));
}

int	printhex(int fd, unsigned int num, t_format **shape)
{
	int	bsr;

	bsr = 0;
	(*shape)->arg = formathex(num, (*shape)->flags);
	if (!(*shape)->arg)
		return (0);
	if (!ft_strlen((*shape)->flags))
	{
		if ((*shape)->type == 'x')
			ft_putnbrhex_fd(((t_typehex *)(*shape)->arg)->value, fd, &bsr, L_BHEX);
		else if ((*shape)->type == 'X')
			ft_putnbrhex_fd(((t_typehex *)(*shape)->arg)->value, fd, &bsr, U_BHEX);
		return (bsr);
	}
	return (printf_formathex(fd, (*shape)->arg));
}

int	printpointer(int fd, unsigned long num, t_format **shape)
{
	int	bsr;

	bsr = 0;
	if (!num)
		return (ft_putstr_fd("(nil)", fd));
	(*shape)->arg = formatpointer(num);
	bsr += ft_putstr_fd("0x", fd);
	ft_putnbrhex_fd(((t_typepointer *)(*shape)->arg)->value, fd, &bsr, L_BHEX);
	return (bsr);
}