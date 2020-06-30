/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:39:12 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 16:47:48 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_term.h"

void	fts_term_init(t_struct *structs)
{
	if ((structs->term_name = getenv("TERM")) == NULL)
		fts_error_init(1, structs);
	if (tgetent(NULL, structs->term_name) <= 0)
		fts_error_init(2, structs);
	if ((structs->fd = open(ttyname(0), O_RDWR | O_NDELAY)) < 0)
		fts_error_init(3, structs);
	tcgetattr(structs->fd, &structs->t_start);
	ft_memcpy(&structs->t_curr, &structs->t_start, sizeof(structs->t_start));
	structs->t_curr.c_lflag &= ~(ICANON | ECHO);
	structs->t_curr.c_oflag &= ~(OPOST);
	structs->t_curr.c_cc[VMIN] = 1;
	structs->t_curr.c_cc[VTIME] = 0;
	if (tcsetattr(structs->fd, TCSANOW, &structs->t_curr) == -1)
		fts_error_init(4, structs);
	ft_putstr_fd(tgetstr("cl", NULL), structs->fd);
	ft_putstr_fd(tgetstr("ti", NULL), structs->fd);
	ft_putstr_fd(tgetstr("vi", NULL), structs->fd);
}

void	fts_term_restore(t_struct *structs)
{
	ft_putstr_fd(tgetstr("cl", NULL), structs->fd);
	ft_putstr_fd(tgetstr("te", NULL), structs->fd);
	ft_putstr_fd(tgetstr("ve", NULL), structs->fd);
	tcsetattr(structs->fd, TCSANOW, &structs->t_start);
}
