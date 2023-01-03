/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:36:32 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/21 07:49:20 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cached_s1;
	unsigned char	*cached_s2;

	i = 0;
	cached_s1 = (unsigned char *)s1;
	cached_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cached_s1[i] != cached_s2[i])
			return (cached_s1[i] - cached_s2[i]);
		i++;
	}
	return (0);
}
