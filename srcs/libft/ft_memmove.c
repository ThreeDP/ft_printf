/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:36:47 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/25 07:43:22 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n_bytes)
{
	unsigned char	*cached_dest;
	unsigned char	*cached_src;

	cached_dest = (unsigned char *)dest;
	cached_src = (unsigned char *)src;
	if (cached_dest < cached_src)
		return (ft_memcpy(dest, src, n_bytes));
	while (n_bytes-- > 0)
		cached_dest[n_bytes] = cached_src[n_bytes];
	return (cached_dest);
}
