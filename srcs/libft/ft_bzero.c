/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:12:13 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/21 07:12:16 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *str, size_t n_bytes)
{
	size_t			byte;
	unsigned char	*cached_str;

	byte = 0;
	cached_str = (unsigned char *)str;
	while ((byte < n_bytes))
	{
		cached_str[byte] = '\0';
		byte++;
	}
}
