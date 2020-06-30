/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:55:39 by eboris            #+#    #+#             */
/*   Updated: 2019/09/28 14:18:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		n;
	size_t	m;
	size_t	l;
	char	*hay;
	char	*need;

	need = (char *)needle;
	hay = (char *)haystack;
	l = ft_strlen(needle);
	if (l == 0)
		return (&hay[0]);
	if (len == 0)
		return (NULL);
	n = -1;
	while (hay[++n] != '\0')
	{
		m = 0;
		if (hay[n] == need[m])
			while ((hay[n + m] == need[m]) && (m <= l))
				if ((++m == l) && (((size_t)n + m <= len)))
					return (&hay[n]);
	}
	return (NULL);
}
