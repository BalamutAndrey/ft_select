/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_term.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 16:36:50 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 14:51:01 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_TERM_H
# define FTS_TERM_H

# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include "libft.h"
# include "fts_structs.h"
# include "fts_errors.h"

void	fts_term_init(t_struct *structs);
void	fts_term_restore(t_struct *structs);

#endif
