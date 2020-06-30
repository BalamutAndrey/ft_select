/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:12:58 by eboris            #+#    #+#             */
/*   Updated: 2019/09/28 15:00:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while ((s1[n] != '\0') && (s2[n] != '\0') &&
			((unsigned char)s1[n] == (unsigned char)s2[n]))
	{
		n++;
	}
	if ((s1[n] == '\0') && (s2[n] == '\0'))
		return (0);
	else
		return ((unsigned char)s1[n] - (unsigned char)s2[n]);
}
