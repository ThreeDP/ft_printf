/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:37:41 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/08 21:13:47 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	s;
	size_t	e;

	if (!s1 || !set)
		return ((char *) ft_calloc(1, 1));
	s = 0;
	e = ft_strlen(s1);
	while (s1[s] && ft_strchr(set, s1[s]))
		s++;
	while (e > 0 && ft_strchr(set, s1[e - 1]) && e > s)
		e--;
	new_s = (char *) ft_calloc((e - s) + 1, sizeof(char));
	if (new_s)
		ft_strlcpy(new_s, &s1[s], (e - s) + 1);
	return (new_s);
}
