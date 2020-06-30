/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:38:30 by eboris            #+#    #+#             */
/*   Updated: 2019/10/06 13:43:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_straddchr(char *str, char c)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(str);
	temp = malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	ft_strdel((char **)&str);
	return (temp);
}
