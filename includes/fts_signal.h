/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_signal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:12:39 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 15:28:24 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_SIGNAL_H
# define FTS_SIGNAL_H

# include <signal.h>
# include "fts_screen_resize.h"
# include "fts_screen_refresh.h"
# include "fts_exit.h"

void	fts_signal_set(void);

#endif
