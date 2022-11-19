/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:31:54 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/19 20:32:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_typestring	*new_typestring(char *str)
{
	t_typestring *c_format;
	
	c_format = (t_typestring *) malloc(sizeof(t_typestring));
	if (!c_format)
		return (NULL);
	c_format->value = str;
	c_format->minus = FALSE;
	c_format->bytes = 0;
	c_format->dot = FALSE;
	c_format->bytes = 0;
	c_format->valid_bytes = 0;
	return (c_format);
}