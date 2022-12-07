/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/30 17:50:57 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Função responsavel por validar se uma sub-string é digit 
e retornar um valor do tipo inteito */
int	sub_atoi(const char *strnum, int *size)
{
	int		i;
	char	*flag;
	int		num;

	i = 0;
	num = 0;
	while (ft_isdigit(strnum[i]))
		i++;
	if (i > 0)
	{
		flag = ft_strndup(strnum, i);
		*size += i;
		num = ft_atoi(flag);
		if (flag)
			free(flag);
	}
	return (num);
}

/* 
Valida se o caracter atual coresponde a flag passada
*/
t_bool	ft_isflag(char flag, char c, int *i)
{
	if (c == flag)
		return (*i += 1, t);
	return (f);
}

/*
Print the spaces set
*/
int	print_spaces(int fd, int *bytes, char c)
{
	int	bsr;

	bsr = 0;
	while (*bytes > 0)
	{
		bsr += ft_putchar_fd(c, fd);
		*bytes -= 1;
	}
	return (bsr);
}

unsigned int	convert_num(int num, char signal)
{
	if (signal == '-')
		return (num * -1);
	return (num * 1);
}

/*
Valida multiplas flags pra a formatação
do tipo inteiro
*/
int	match_iflags(char *flags, t_bool *f1, t_typeint **format, char flag)
{
	int	i;

	i = 0;
	while (flags[i] == flag || flags[i] == ' ' || flags[i] == '+')
	{
		if (!*f1 && flags[i] == flag)
			*f1 = ft_isflag(flag, flags[i], &i);
		else if (!(*format)->space && flags[i] == ' ')
			(*format)->space = ft_isflag(' ', flags[i], &i);
		else if (!(*format)->plus && flags[i] == '+')
			(*format)->plus = ft_isflag('+', flags[i], &i);
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

void	format_dot(t_typeint **format, int size)
{
	if ((*format)->fzero && !(*format)->minus && !(*format)->dot)
		(*format)->bytes_s = (*format)->bytes - size;
	if ((*format)->dot)
	{
		(*format)->bytes_s -= size;
		(*format)->bytes -= ((*format)->bytes_s + size);
		return ;
	}
	(*format)->bytes -= size;
	(*format)->bytes -= (*format)->bytes_s;
}