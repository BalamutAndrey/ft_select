/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_key_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 16:31:40 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:18:26 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_key_right.h"

void	fts_key_right(t_struct *structs)
{
	uint16_t	z;
	t_args		*temp;

	z = 0;
	temp = structs->first;
	while (++z < structs->args_nb)
	{
		if (temp->curr == 1)
		{
			temp->curr = 0;
			temp = temp->next;
			temp->curr = 1;
			z = structs->args_nb;
		}
		temp = temp->next;
	}
	ft_putstr_fd(tgetstr("cl", NULL), structs->fd);
	fts_args_print(structs);
}
