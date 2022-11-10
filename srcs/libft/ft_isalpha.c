/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 07:35:44 by dapaulin          #+#    #+#             */
/*   Updated: 2022/10/08 18:45:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (0);
	return (1 << 10);
}

static int	ft_isupper(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (0);
	return (1 << 10);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1 << 10);
	return (0);
}
