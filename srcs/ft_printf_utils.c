/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapaulin <dapaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:29 by dapaulin          #+#    #+#             */
/*   Updated: 2022/11/26 15:13:07 by dapaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Função responsavel por validar se uma sub-string é digit 
e retornar um valor do tipo inteito */
int	sub_atoi(const char *strnum, int *size)
{
	int		i;
	char 	*flag;
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
		if (!flag)
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
		return (*i+=1, true);
	return (false);
}
