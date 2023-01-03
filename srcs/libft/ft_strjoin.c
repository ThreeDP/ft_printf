/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:06:59 by dapaulin          #+#    #+#             */
/*   Updated: 2022/09/25 17:34:33 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = (char *) malloc((len_s1 + len_s2) * sizeof(char) + 1);
	if (!new_str)
		return (new_str);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	ft_strlcpy(&new_str[len_s1], s2, len_s2 + 1);
	return (new_str);
}
