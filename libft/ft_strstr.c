/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:50:30 by eboris            #+#    #+#             */
/*   Updated: 2019/09/10 21:34:46 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	n;
	size_t	m;
	size_t	z;
	char	*hay;
	char	*need;

	need = (char *)needle;
	hay = (char *)haystack;
	n = 0;
	z = ft_strlen(need);
	if (z == 0)
		return (&hay[0]);
	while (hay[n] != '\0')
	{
		m = 0;
		if (hay[n] == need[m])
			while ((hay[n + m] == need[m]) && (m <= z))
			{
				if (m == z - 1)
					return (&hay[n]);
				m++;
			}
		n++;
	}
	return (NULL);
}
