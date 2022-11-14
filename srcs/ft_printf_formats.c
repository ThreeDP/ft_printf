/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:07:55 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/14 14:20:49 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

t_typechar	*formatchar(char c)
{
	t_typechar	*format;

	format = malloc(sizeof(t_typechar));
	if (!format)
		return (NULL);
	format->value = c;
	return (format);
}

t_typestring	*formatstring(char *str)
{
	t_typestring	*format;

	format = malloc(sizeof(t_typechar));
	if (!format)
		return (NULL);
	format->value = ft_strdup(str);
	if (!format->value)
		return (free(format), NULL);
	return (format);
}

t_typeint	*formatint(int integer)
{
	t_typeint	*format;

	format = malloc(sizeof(t_typeint));
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

t_typehex	*formathex(unsigned int num)
{
	t_typehex	*format;

	format = malloc(sizeof(t_typehex));
	if (!format)
		return (NULL);
	format->value = num;
	return (format);
}
