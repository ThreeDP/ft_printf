/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/29 18:08:22 by dapaulin         ###   ########.fr       */
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
