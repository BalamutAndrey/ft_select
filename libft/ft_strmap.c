/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:05:37 by eboris            #+#    #+#             */
/*   Updated: 2019/10/05 19:47:39 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (f)(char))
{
	char	*temp;
	size_t	len;
	size_t	i;

	if (!s || !*s || !f)
		return (NULL);
	len = ft_strlen(s);
	temp = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!temp)
		return (NULL);
	while (i < len)
	{
		temp[i] = f((char)s[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
