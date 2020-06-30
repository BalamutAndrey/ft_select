/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_args_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:23:41 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:40:50 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_args_print.h"

void	fts_args_print(t_struct *structs)
{
	t_args		*temp;
	uint32_t	i;
	uint16_t	z;

	z = 0;
	temp = structs->first;
	while (++z < structs->args_nb)
	{
		if (temp->curr == 1)
			ft_putstr_fd(tgetstr("us", NULL), structs->fd);
		if (temp->selected == 1)
			ft_putstr_fd(tgetstr("so", NULL), structs->fd);
		ft_putstr_fd(temp->name, structs->fd);
		ft_putstr_fd(tgetstr("ue", NULL), structs->fd);
		ft_putstr_fd(tgetstr("se", NULL), structs->fd);
		i = ft_strlen(temp->name);
		while (i <= structs->max_len)
		{
			ft_putchar_fd(' ', structs->fd);
			i++;
		}
		temp = temp->next;
	}
}
