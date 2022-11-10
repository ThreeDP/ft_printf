/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:36:41 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/21 07:48:31 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n_bytes)
{
	size_t			byte;
	unsigned char	*cached_dest;
	unsigned char	*cached_src;

	byte = 0;
	cached_dest = (unsigned char *)dest;
	cached_src = (unsigned char *)src;
	while (byte < n_bytes)
	{
		cached_dest[byte] = cached_src[byte];
		byte++;
	}
	return (cached_dest);
}
