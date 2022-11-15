/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:21:12 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/14 20:24:02 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(unsigned int nb, int fd, int *ret)
{
	char			c;

	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, ret);
	c = (nb % 10) + 48;
	*ret += ft_putchar_fd(c, fd);
}

void	ft_putnbrhex_fd(ssize_t nb, int fd, int *ret, char *caset)
{
	if (nb >= 16)
		ft_putnbrhex_fd(nb / 16, fd, ret, caset);
	*ret += ft_putchar_fd(caset[(nb % 16)], fd);
}
