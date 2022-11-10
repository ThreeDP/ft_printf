/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:37:07 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/05 01:02:13 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;	
	char	*cached_src;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	cached_src = (char *)src;
	if (size <= len_dst)
		return (size + len_src);
	while (cached_src[i] && (len_dst + 1) < size)
		dst[len_dst++] = cached_src[i++];
	dst[len_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&cached_src[i]));
}
