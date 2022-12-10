/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/09 20:11:52 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int	i;

	i = 0;
	while (!ft_istype(str[i]))
		i++;
	return (i);
}

int	select_type(va_list *args, t_format **shape, int fd)
{
	int	bsr;

	bsr = 0;
	if ((*shape)->type == 'c')
		bsr = printchar(fd, va_arg(*args, int), shape);
	else if ((*shape)->type == 's')
		bsr = printstring(fd, va_arg(*args, char *), shape);
	else if ((*shape)->type == 'i' || (*shape)->type == 'd')
		bsr = printint(fd, va_arg(*args, int), shape);
	else if ((*shape)->type == 'u')
		bsr = printint(fd, va_arg(*args, int), shape);
	else if ((*shape)->type == 'x' || (*shape)->type == 'X')
		bsr = printhex(fd, va_arg(*args, unsigned int), shape);
	else if ((*shape)->type == 'p')
		bsr = printhex(fd, va_arg(*args, unsigned long), shape);
	else if ((*shape)->type == '%')
		bsr = printchar(fd, '%', shape);
	if ((*shape)->arg)
		free((*shape)->arg);
	(*shape)->arg = NULL;
	if ((*shape)->flags)
		free((*shape)->flags);
	(*shape)->flags = NULL;
	return (bsr);
}

int	ft_printf(const char *str, ...)
{
	va_list		args_str;
	t_format	*shape;
	int			num_bytes;
	char		*percent;
	char		*cached_str;

	num_bytes = 0;
	cached_str = (char *)str;
	shape = new_format();
	if (!str)
		return (-1);
	va_start(args_str, str);
	percent = ft_strchr(cached_str, '%');
	while (percent)
	{
		num_bytes += write(1, cached_str, (percent - cached_str));
		cached_str += (percent - cached_str) + 1;
		shape->f_pos = findflag(cached_str);
		shape->type = cached_str[shape->f_pos];
		shape->flags = ft_strndup(cached_str, shape->f_pos);
		num_bytes += select_type(&args_str, &shape, 1);
		cached_str += shape->f_pos + 1;
		percent = ft_strchr(cached_str, '%');
	}
	num_bytes += ft_putstr_fd(cached_str, 1);
	if (shape)
		free(shape);
	va_end(args_str);
	return (num_bytes);
}
