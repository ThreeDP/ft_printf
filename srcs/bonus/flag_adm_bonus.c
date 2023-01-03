/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_adm_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:28:44 by dapaulin          #+#    #+#             */
/*   Updated: 2023/01/03 18:14:48 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	match_iflags(char *f, t_bool *f1, t_typeint **format, char c)
{
	int	i;

	i = 0;
	while (f[i] == c || f[i] == ' ' || f[i] == '+')
	{
		if (!*f1 && f[i] == c)
			*f1 = ft_isflag(c, f[i], &i);
		else if (!(*format)->space && f[i] == ' ')
			(*format)->space = ft_isflag(' ', f[i], &i);
		else if (!(*format)->plus && f[i] == '+')
			(*format)->plus = ft_isflag('+', f[i], &i);
		else
			i++;
	}
	return (i);
}

int	match_xflags(char *flags, t_bool *f1, t_bool *f2, char flag)
{
	int	i;

	i = 0;
	while (flags[i] == flag || flags[i] == '#')
	{
		if (!*f1 && flags[i] == flag)
			*f1 = ft_isflag(flag, flags[i], &i);
		else if (!*f2 && flags[i] == '#')
			*f2 = ft_isflag('#', flags[i], &i);
		else
			i++;
	}
	return (i);
}

void	format_xflags(t_typehex **format, int size)
{
	if ((*format)->hash && (*format)->bytes > 0)
		(*format)->bytes -= 2;
	if ((*format)->fzero && !(*format)->minus && !(*format)->dot)
		(*format)->bytes_s = (*format)->bytes - size;
	if ((*format)->dot)
	{
		if ((*format)->bytes_s > size)
			(*format)->bytes_s -= size;
		else
			(*format)->bytes_s = 0;
		(*format)->bytes -= ((*format)->bytes_s + size);
		return ;
	}
	(*format)->bytes -= size;
	(*format)->bytes -= (*format)->bytes_s;
}

void	format_iflags(t_typeint **format, int size)
{
	if (((*format)->plus || (*format)->signal == '-') && (*format)->bytes > 0)
		(*format)->bytes -= 1;
	else if ((*format)->space)
		(*format)->bytes -= 1;
	if ((*format)->fzero && !(*format)->minus && !(*format)->dot)
		(*format)->bytes_s = (*format)->bytes - size;
	if ((*format)->dot)
	{
		if ((*format)->bytes_s > size)
			(*format)->bytes_s -= size;
		else
			(*format)->bytes_s = 0;
		(*format)->bytes -= ((*format)->bytes_s + size);
		return ;
	}
	(*format)->bytes -= size;
	(*format)->bytes -= (*format)->bytes_s;
}
