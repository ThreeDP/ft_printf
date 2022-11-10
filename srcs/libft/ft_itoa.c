/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:49:42 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/29 10:22:05 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setminus(int *count, int n)
{
	if (n < 0)
		return (*count += 1, -1);
	return (1);
}

static char	*ft_itoa_count(unsigned int n, int *count)
{
	char	*ptr;

	if (n >= 10)
	{
		*count += 1;
		ptr = ft_itoa_count(n / 10, count);
	}
	else
		ptr = (char *) ft_calloc(*count + 1, sizeof(char));
	return (ptr);
}

static void	ft_itoa_aux(unsigned int n, int count, char *ptr)
{
	if (n >= 10)
		ft_itoa_aux(n / 10, count - 1, ptr);
	ptr[count] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		count;
	int		signal;

	count = 1;
	signal = ft_setminus(&count, n);
	ptr = ft_itoa_count(n * signal, &count);
	if (signal == -1)
		ptr[0] = '-';
	ft_itoa_aux(n * signal, count -1, ptr);
	return (ptr);
}
