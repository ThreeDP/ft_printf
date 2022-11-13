/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:21:12 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/13 14:59:14 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(unsigned int nb, int fd, int *ret)
{
	char			c;

	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, ret);
	c = (nb % 10) + 48;
	ft_putchar_fd(c, fd);
	*ret += 1;
}
