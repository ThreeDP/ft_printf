/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:21:12 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/25 21:28:13 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char			c;
	unsigned int	num;
	int				signal;

	signal = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		signal = -1;
	}
	num = nb * signal;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + 48;
	ft_putchar_fd(c, fd);
}
