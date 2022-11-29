/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:07:55 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/29 09:02:54 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_typechar	*formatchar(char c, const char *flags)
{
	int			i;
	t_typechar	*format;

	i = 0;
	format = new_typechar(c);
	if (!format)
		return (NULL);
	format->minus = ft_isflag('-', flags[i], &i);
	while (flags[i] == '-')
		i++;
	format->bytes = sub_atoi(&flags[i], &i);
	format->valid_bytes = i;
	return (format);
}

t_typestring	*formatstring(char *str, const char *flags)
{
	int				i;
	t_typestring	*format;

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
