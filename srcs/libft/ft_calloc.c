/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 22:00:12 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/08 19:31:24 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	if (nmemb >= ~(1 << 31) || size >= ~(1 << 31) || !nmemb || !size)
		return (0);
	len = nmemb * size;
	ptr = (unsigned char *) malloc(len);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, len);
	return (ptr);
}
