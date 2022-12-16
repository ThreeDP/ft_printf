/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:36:21 by dapaulin          #+#    #+#             */
/*   Updated: 2022/12/09 22:05:11 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	printchar(int fd, char c, t_format **shape)
{
	(*shape)->arg = formatchar(c, (*shape)->flags);
	if (!(*shape)->arg)
		return (0);
	return (printf_formatchar(fd, (*shape)->arg));
}

int	printstring(int fd, char *str, t_format **shape)
{
	int		bsr;
	char	*pnull;

	pnull = NULL;
	if  (!str)
	{
		pnull = ft_strdup("(null)");
		(*shape)->arg = formatstring(pnull, (*shape)->flags);
	}
	else
		(*shape)->arg = formatstring(str, (*shape)->flags);
	if (!(*shape)->arg)
		return (0);
	bsr = printf_formatstring(fd, (*shape)->arg);
	if (pnull)
		free(pnull);
	return (bsr);
}

int	printint(int fd, int integer, t_format **shape)
{
	(*shape)->arg = formatint(integer, (*shape)->flags, (*shape)->type);
	if (!(*shape)->arg)
		return (0);
	return (printf_formatint(fd, (*shape)->arg));
}

int	printhex(int fd, unsigned long num, t_format **shape)
{
	if (!num && (*shape)->type == 'p')
		return (printstring(fd, "(nil)", shape));
	else
		(*shape)->arg = formathex(num, (*shape)->flags, (*shape)->type);
	if (!(*shape)->arg)
		return (0);
	return (printf_formathex(fd, (*shape)->arg));
}
