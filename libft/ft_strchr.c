/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:29:21 by eboris            #+#    #+#             */
/*   Updated: 2019/09/08 21:18:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*fin;

	i = 0;
	fin = (char *)s;
	if (c == 0)
	{
		while (fin[i] != '\0')
			i++;
		return (&fin[i]);
	}
	while ((fin[i] != '\0') && (fin[i] != c))
		i++;
	if (fin[i] == '\0')
		return (NULL);
	return (&fin[i]);
}
