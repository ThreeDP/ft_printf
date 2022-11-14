/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/14 14:17:07 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	printchar(int fd, char c, t_list **lst)
{
	int	bsr;

	(*lst)->arg = formatchar(c);
	bsr = ft_putchar_fd(((t_typechar *)(*lst)->arg)->value, fd);
	ft_lstadd_back(lst, ft_lstnew('\0', NULL));
	return (bsr);
}

int	printstring(int fd, char *str, t_list **lst)
{
	int	bsr;

	(*lst)->arg = formatstring(str);
	bsr = ft_putstr_fd(((t_typestring *)(*lst)->arg)->value, fd);
	ft_lstadd_back(lst, ft_lstnew('\0', NULL));
	return (bsr);
}

int	printinteger(int fd, int integer, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formatint(integer);
	if (((t_typeint *)(*lst)->arg)->signal == '-')
		bsr += ft_putchar_fd('-', fd);
	ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
	ft_lstadd_back(lst, ft_lstnew('\0', NULL));
	return (bsr);
}

int	printuinteger(int fd, int uinteger, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formatint(uinteger);
	ft_putnbr_fd(((t_typeint *)(*lst)->arg)->value, fd, &bsr);
	ft_lstadd_back(lst, ft_lstnew('\0', NULL));
	return (bsr);
}

int	printhex(int fd, unsigned int num, t_list **lst)
{
	int	bsr;

	bsr = 0;
	(*lst)->arg = formathex(num);
	if ((*lst)->type == 'x')
		ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, L_BHEX);
	else if ((*lst)->type == 'X')
		ft_putnbrhex_fd(((t_typehex *)(*lst)->arg)->value, fd, &bsr, U_BHEX);
	ft_lstadd_back(lst, ft_lstnew('\0', NULL));
	return (bsr);
}
