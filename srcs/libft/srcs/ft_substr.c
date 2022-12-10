/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:00:24 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/08 21:13:52 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_sub;
	size_t	l;

	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (l >= len)
		l = len;
	if (ft_strlen(s) - start < l)
		l = ft_strlen(&s[start]);
	new_sub = (char *) ft_calloc(l + 1, sizeof(char));
	if (new_sub)
		ft_strlcpy(new_sub, &s[start], l + 1);
	return (new_sub);
}
