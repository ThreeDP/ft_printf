/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/29 07:05:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'X')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return (1);
	return (0);
}

int	findflag(char *str)
{
	int i;
	
	i = 0;
	while (!ft_istype(str[i]))
		i++;
	return (i);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list		args_str;
	t_format	*shape;
	int			num_bytes;
	int			bsr;
	char		*percent;
	char		*cached_str;

	num_bytes = 0;

	cached_str = (char *)str;
	shape = new_format();
	va_start(args_str, str);
	percent = ft_strchr(cached_str, '%');
	while (percent)
	{
		num_bytes += write(fd, cached_str, (percent - cached_str));
		cached_str += (percent - cached_str) + 1;
		shape->f_pos = findflag(cached_str);
		shape->type = cached_str[shape->f_pos];
		shape->flags = ft_strndup(cached_str, shape->f_pos);
		if (shape->type == 'c')
			bsr = printchar(fd, va_arg(args_str, int), &shape);
		else if (shape->type == 's')
			bsr = printstring(fd, va_arg(args_str, char *), &shape);
		else if (shape->type == 'i' || shape->type == 'd')
			bsr = printinteger(fd, va_arg(args_str, int), &shape);
		else if (shape->type == 'u')
			bsr = printuinteger(fd, va_arg(args_str, int), &shape);
		else if (shape->type == 'x' || shape->type == 'X')
			bsr = printhex(fd, va_arg(args_str, int), &shape);
		else if (shape->type == 'p')
			bsr = printpointer(fd, va_arg(args_str, unsigned long), &shape);
		else if (shape->type == '%')
			bsr = printchar(fd, '%', &shape);
		cached_str+= shape->f_pos + 1;
		num_bytes += bsr;
		if (shape->arg)
		{
			free(shape->arg);
			shape->arg = NULL;
		}
		if (shape->flags)
		{
			free(shape->flags);
			shape->flags = NULL;
		}
		percent = ft_strchr(cached_str, '%');
	}
	num_bytes += ft_putstr_fd(cached_str, fd);
	if (shape)
		free(shape);
	va_end(args_str);
	return (num_bytes);
}
