/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:36:54 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/21 07:48:15 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *str, int c_fill, size_t n_bytes)
{
	size_t			byte;
	unsigned char	*cached_str;

	byte = 0;
	cached_str = (unsigned char *)str;
	while (byte < n_bytes)
	{
		cached_str[byte] = c_fill;
		byte++;
	}
	return (cached_str);
}
