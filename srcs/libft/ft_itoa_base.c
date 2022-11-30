/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:49:42 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 19:02:09 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define U_BHEX "0123456789ABCDEF"

static char	*ft_itoa_count(unsigned int n, int *count, unsigned int base)
{
	char	*ptr;

	ptr = NULL;
	if (n >= base)
	{
		*count += 1;
		ft_itoa_count(n / base, count, base);
	}
	else
		ptr = (char *) ft_calloc(*count + 1, sizeof(char));
	return (ptr);
}

static void	ft_itoa_aux(unsigned int n, int count, char *ptr, unsigned int base)
{
	if (n >= base)
		ft_itoa_aux(n / base, count - 1, ptr, base);
	if (base <= 10)
		ptr[count] = (n % base) + '0';
	if (base == 16)
		ptr[count] = U_BHEX[n % base];
}

char	*ft_itoa_base(unsigned int n, unsigned int base)
{
	char	*ptr;
	int		count;

	count = 1;
	ptr = ft_itoa_count(n, &count, base);
	ft_itoa_aux(n, count -1, ptr, base);
	return (ptr);
}
