/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:49:15 by eboris            #+#    #+#             */
/*   Updated: 2019/09/18 14:11:02 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (alst != NULL)
	{
		tmp = *alst;
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			ft_lstdelone(&tmp, del);
			tmp = tmp2;
		}
		*alst = NULL;
	}
}
