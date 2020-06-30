/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_screen_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:18:14 by eboris            #+#    #+#             */
/*   Updated: 2020/03/12 14:24:12 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_screen_resize.h"

void	fts_screen_resize(int a)
{
	extern t_struct	*g_structs;

	(void)a;
	ft_putstr_fd(tgetstr("cl", NULL), g_structs->fd);
	fts_args_print(g_structs);
}
