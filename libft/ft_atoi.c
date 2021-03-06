/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:36:40 by eboris            #+#    #+#             */
/*   Updated: 2020/02/19 15:17:11 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atoi_atoi(char *str, int minus)
{
	int		i;
	long	fin;

	i = 0;
	fin = 0;
	while (((unsigned char)str[i] >= '0') && ((unsigned char)str[i] <= '9'))
	{
		if ((((fin * 10) + (str[i] - 48)) < fin) && (minus == 1))
			return (-1);
		else if ((((fin * 10) + (str[i] - 48)) < fin) && (minus == -1))
			return (0);
		fin = (fin * 10) + ((unsigned char)str[i] - 48);
		i++;
	}
	return (fin);
}

int			ft_atoi(const char *str)
{
	int		i;
	long	fin;
	char	*s;
	int		minus;

	i = 0;
	s = (char *)str;
	minus = 1;
	while (((s[i] == '\t') || (s[i] == '\n') || (s[i] == '\v') ||
			(s[i] == '\f') || (s[i] == '\r') || (s[i] == '\x1b') ||
			(s[i] == ' ')) && (s[i] != '\e'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	fin = ft_atoi_atoi(&s[i], minus);
	fin = fin * minus;
	return ((int)fin);
}
