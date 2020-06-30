/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:58:13 by eboris            #+#    #+#             */
/*   Updated: 2019/10/05 16:02:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			n;
	char			*tmp;

	i = 0;
	n = 0;
	if (!s || !*s)
		return (NULL);
	while ((s[i] != '\0') && (i < start))
		i++;
	if (i != start)
		return (NULL);
	tmp = malloc((len + 1) * sizeof(char));
	if (!(tmp))
		return (NULL);
	while ((s[i] != '\0') && (n < len))
	{
		tmp[n] = s[i];
		i++;
		n++;
	}
	tmp[n] = '\0';
	if (n != len)
		return (NULL);
	return (tmp);
}
