/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 07:10:25 by eboris            #+#    #+#             */
/*   Updated: 2019/09/19 08:46:57 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*ss1;
	char	*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	while ((i < n) && ((unsigned char)ss1[i] == (unsigned char)ss2[i]))
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
