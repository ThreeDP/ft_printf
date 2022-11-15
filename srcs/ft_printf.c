/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:36:22 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/15 06:46:36 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == '%' || c == 'X')
		return (1);
	else if (c == 'd' || c == 'i' || c == 'u' || c == 'x')
		return (1);
	return (0);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args_str;
	t_list	*lst_args;
	t_list	*lst_free;
	int		num_bytes;
	int		bsr;
	char	*percent;
	char	*cached_str;

	num_bytes = 0;

	cached_str = (char *)str;
	lst_args = ft_lstnew('\0', NULL);
	lst_free = lst_args;
	va_start(args_str, str);
	percent = ft_strchr(cached_str, '%');
	while (percent)
	{
		num_bytes += write(fd, cached_str, (percent - cached_str));
		cached_str += (percent - cached_str) + 1;
		lst_args->type = *cached_str;
		if (lst_args->type == 'c')
			bsr = printchar(fd, va_arg(args_str, int), &lst_args);
		else if (lst_args->type == 's')
			bsr = printstring(fd, va_arg(args_str, char *), &lst_args);
		else if (lst_args->type == 'i' || lst_args->type == 'd')
			bsr = printinteger(fd, va_arg(args_str, int), &lst_args);
		else if (lst_args->type == 'u')
			bsr = printuinteger(fd, va_arg(args_str, int), &lst_args);
		else if (lst_args->type == 'x' || lst_args->type == 'X')
			bsr = printhex(fd, va_arg(args_str, int), &lst_args);
		else if (lst_args->type == 'p')
			bsr = printpointer(fd, va_arg(args_str, ssize_t), &lst_args);
		else if (lst_args->type == '%')
			bsr = printchar(fd, '%', &lst_args);
		cached_str++;
		if (!bsr)
			return (ft_lstclear(&lst_free, free), num_bytes);
		num_bytes += bsr;
		ft_lstadd_back(&lst_args, ft_lstnew('\0', NULL));
		lst_args = lst_args->next;
		percent = ft_strchr(cached_str, '%');
	}
	num_bytes += ft_putstr_fd(cached_str, fd);
	ft_lstclear(&lst_free, free);
	va_end(args_str);
	return (num_bytes);
}
