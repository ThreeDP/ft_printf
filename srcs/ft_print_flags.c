/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/01 19:43:05 by dapaulin         ###   ########.fr       */
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
		bsr += print_spaces(fd, &format->bytes, ' ');
	bsr += ft_putchar_fd(format->value, fd);
	bsr += print_spaces(fd, &format->bytes, ' ');
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
		bsr += print_spaces(fd, &format->bytes, ' ');
	bsr += write(fd, format->value, size);
	bsr += print_spaces(fd, &format->bytes, ' ');
	return (bsr);
}

int	printf_formathex(int fd, t_typehex *format)
{
	int	bsr;

	bsr = 0;
	if (!format->minus)
		bsr += print_spaces(fd, &format->bytes, ' ');
	bsr += print_spaces(fd, &format->bytes, ' ');
	return (bsr);
}

int printf_formatint(int fd, t_typeint *format)
{
	int 	i;
	int 	bsr;
	int 	size;
	int		signal;
	char	*str_num;
	int		test = 1;

	i = 0;
	bsr = 0;
	signal = 0;
	str_num = ft_itoa(format->value);
	size = ft_strlen(str_num);
	if (format->bytes_s > size)
		format->bytes_s -= size;
	if (format->signal == '-' || format->plus)
		signal = 1;
	if ((!format->bytes_s && !format->dot) || size <= format->bytes_s)
		format->bytes -= (size + signal);
	if ((format->signal == '-' || format->plus) && (format->fzero || format->dot))
	{
		test = 0;
		bsr += ft_putchar_fd(format->signal, fd);
	}
	if (!format->minus && (format->fzero || format->dot))
	{
		if (format->bytes)
			format->bytes -= format->bytes_s;
		if (format->bytes_s)
			bsr += print_spaces(fd, &format->bytes, ' ');
		else if (format->dot && format->bytes_s)
			bsr += print_spaces(fd, &format->bytes_s, '0');
		else
			bsr += print_spaces(fd, &format->bytes, '0');
		bsr += print_spaces(fd, &format->bytes_s, '0');
	}
	else if (format->minus && format->bytes_s)
	{
		bsr += print_spaces(fd, &format->bytes_s, '0');
	}
	else if (!format->minus) {
		bsr += print_spaces(fd, &format->bytes, ' ');
	}
	if ((format->signal == '-' || format->plus) && !format->fzero && test)
		bsr += ft_putchar_fd(format->signal, fd);
	bsr += write(fd, &str_num[i], size);
	bsr += print_spaces(fd, &format->bytes, ' ');
	if (str_num)
		free(str_num);
	return (bsr);
}