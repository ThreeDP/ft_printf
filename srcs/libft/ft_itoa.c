/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:49:42 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 05:49:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(unsigned int n)
{
	char	*ptr;
	int		count;

	count = 1;
	ptr = ft_itoa_count(n, &count);
	ft_itoa_aux(n, count -1, ptr);
	return (ptr);
}
