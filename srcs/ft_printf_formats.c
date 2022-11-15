/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:07:55 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/15 10:47:06 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_typechar	*formatchar(char c)
{
	t_typechar	*format;

	format = (t_typechar *) malloc(sizeof(t_typechar));
	if (!format)
		return (NULL);
	format->value = c;
	return (format);
}

t_typestring	*formatstring(char *str)
{
	t_typestring	*format;

	format = (t_typestring *) malloc(sizeof(t_typestring));
	if (!format)
		return (NULL);
	format->value = str;
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
