/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:07:55 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/19 20:28:25 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

t_typechar	*formatchar(char c)
{
	t_typechar	*format;

	format = (t_typechar *) malloc(sizeof(t_typechar));
	if (!format)
		return (NULL);
	format->value = c;
	return (format);
}

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

t_typestring	*formatstring(char *str, const char *flags)
{
	t_typestring	*format;
	int				i;

	i = 0;
	format = new_typestring(str);
	if (!format)
		return (NULL);
	format->minus = ft_isflag('-', flags[i], &i);
	while (flags[i] == '-')
		i++;
	format->bytes = sub_atoi(&flags[i], &i);
	format->dot = ft_isflag('.', flags[i], &i);
	format->bytes_s = sub_atoi(&flags[i], &i);
	format->valid_bytes = i;
	return (format);
}

t_typeint	*formatint(int integer)
{
	t_typeint	*format;

	format = (t_typeint *) malloc(sizeof(t_typeint));
	if (!format)
		return (NULL);
	if (integer < 0)
	{
		format->signal = '-';
		format->value = integer * -1;
	}
	else
	{
		format->signal = '+';
		format->value = integer * 1;
	}
	return (format);
}

t_typeint	*formatuint(int uinteger)
{
	t_typeint	*format;

	format = (t_typeint *) malloc(sizeof(t_typeint));
	if (!format)
		return (NULL);
	if (uinteger < 0)
		format->signal = '-';
	else
		format->signal = '+';
	format->value = uinteger * 1;
	return (format);
}

t_typehex	*formathex(unsigned int num)
{
	t_typehex	*format;

	format = (t_typehex *) malloc(sizeof(t_typehex));
	if (!format)
		return (NULL);
	format->value = num;
	return (format);
}

t_typepointer	*formatpointer(unsigned long num)
{
	t_typepointer	*format;

	format = (t_typepointer *) malloc(sizeof(t_typepointer));
	if (!format)
		return (NULL);
	format->value = num;
	return (format);
}
