/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:30:28 by eboris            #+#    #+#             */
/*   Updated: 2019/09/26 16:37:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	*tmp;

	tmp = malloc(size * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
