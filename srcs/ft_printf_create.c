/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:31:54 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/29 18:38:26 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*new_format(void)
{
	t_format	*c_format;

	c_format = (t_format *) malloc(sizeof(t_format));
	if (!c_format)
		return (NULL);
	c_format->arg = NULL;
	c_format->flags = NULL;
	c_format->f_pos = 0;
	c_format->type = '\0';
	return (c_format);
}

t_typechar	*new_typechar(char c)
{
	t_typechar	*c_format;

	c_format = (t_typechar *) malloc(sizeof(t_format));
	if (!c_format)
		return (NULL);
	c_format->value = c;
	c_format->minus = f;
	c_format->bytes = 0;
	c_format->valid_bytes = 0;
	return (c_format);
}

t_typestring	*new_typestring(char *str)
{
	t_typestring	*c_format;

	c_format = (t_typestring *) malloc(sizeof(t_typestring));
	if (!c_format)
		return (NULL);
	c_format->value = str;
	c_format->minus = f;
	c_format->bytes = 0;
	c_format->dot = f;
	c_format->bytes_s = 0;
	c_format->valid_bytes = 0;
	return (c_format);
}

t_typeint	*new_typeint(unsigned int num, char signal)
{
	t_typeint	*c_format;

	c_format = (t_typeint *) malloc(sizeof(t_typeint));
	if (!c_format)
		return (NULL);
	c_format->signal = signal;
	c_format->value = num;
	c_format->minus = f;
	c_format->bytes = 0;
	c_format->dot = f;
	c_format->bytes = 0;
	c_format->valid_bytes = 0;
	return (c_format);
	
}