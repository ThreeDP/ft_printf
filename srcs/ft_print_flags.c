/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 06:33:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printf_formatchar(int fd, t_typechar *format)
{
	int	bsr;

	bsr = 0;
	format->bytes--;
	if (!format->minus)
		bsr += print_spaces(fd, &format->bytes);
	bsr += ft_putchar_fd(format->value, fd);
	bsr += print_spaces(fd, &format->bytes);
	return (bsr);
}

int	printf_formatstring(int fd, t_typestring *format)
{
	int	bsr;
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

int printf_formatint(int fd, t_typeint *format)
{
	int 	i;
	int 	bsr;
	int 	size;
	int		signal;
	char	*str_num;

	i = 0;
	bsr = 0;
	signal = 0;
	str_num = ft_itoa(format->value);
	size = ft_strlen(str_num);
	if (format->signal == '-' || format->plus)
		signal = 1;
	if ((!format->bytes_s && !format->dot) || size <= format->bytes_s)
		format->bytes -= (size + signal);
	if (!format->minus)
		bsr += print_spaces(fd, &format->bytes);
	if (format->signal == '-' || format->plus)
		bsr += ft_putchar_fd(format->signal, fd);
	bsr += write(fd, &str_num[i], size);
	bsr += print_spaces(fd, &format->bytes);
	if (str_num)
		free(str_num);
	return (bsr);
}