/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 21:34:47 by eboris            #+#    #+#             */
/*   Updated: 2019/09/11 00:04:37 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*fin;

	fin = (char *)s;
	n = ft_strlen(fin);
	while (n >= 0)
	{
		if (fin[n] == c)
		{
			return (&fin[n]);
		}
		n--;
	}
	return (NULL);
}
