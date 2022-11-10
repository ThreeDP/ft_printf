/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:36:25 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/25 16:04:12 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*cached_str;
	char	cached_c;

	i = 0;
	cached_str = (char *)str;
	cached_c = (char)c;
	while (i < n)
	{
		if (cached_str[i] == cached_c)
			return (&cached_str[i]);
		i++;
	}
	return (0);
}
