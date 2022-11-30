/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:10:07 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 18:59:42 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signdetect(int c, int *pos)
{	
	if (c == '-')
		return (*pos += 1, -1);
	else if (c == '+')
		return (*pos += 1, 1);
	return (1);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1 << 10);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		pos;
	int		nbr;
	int		sign;

	pos = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	sign = ft_signdetect(nptr[pos], &pos);
	nbr = 0;
	while (ft_isdigit(nptr[pos]))
	{
		nbr *= 10;
		nbr += (nptr[pos] - '0');
		pos++;
	}
	return (nbr * sign);
}
