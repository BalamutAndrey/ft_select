/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:12:18 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 15:28:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_signal.h"

void	fts_signal_set(void)
{
	signal(SIGWINCH, fts_screen_resize);
	signal(SIGCONT, fts_screen_refresh);
	signal(SIGINT, fts_exit);
	signal(SIGQUIT, fts_exit);
	signal(SIGABRT, fts_exit);
	signal(SIGKILL, fts_exit);
	signal(SIGTERM, fts_exit);
	signal(SIGSTOP, fts_exit);
}
