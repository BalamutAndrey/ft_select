/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:21:56 by eboris            #+#    #+#             */
/*   Updated: 2019/10/05 16:34:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy_trim(char *tmp, int i)
{
	int		n;
	char	*str;

	while ((tmp[i] == ' ') || (tmp[i] == '\n') || (tmp[i] == '\t'))
		i--;
	n = i + 1;
	str = malloc(n * sizeof(char));
	if (!(str))
		return (NULL);
	while (i >= 0)
	{
		str[i] = tmp[i];
		i--;
	}
	str[n] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	char	*tmp;
	char	*str;

	i = 0;
	n = 0;
	if (!s)
		return (NULL);
	tmp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(tmp))
		return (NULL);
	while ((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		i++;
	while (s[i] != '\0')
	{
		tmp[n] = s[i];
		n++;
		i++;
	}
	i = n - 1;
	str = ft_strcpy_trim(tmp, i);
	if (!(str))
		return (NULL);
	return (str);
}
