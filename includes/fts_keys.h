/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:31:26 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 16:49:40 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_KEYS_H
# define FTS_KEYS_H

# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "fts_structs.h"
# include "fts_key_escape.h"
# include "fts_key_space.h"
# include "fts_key_enter.h"
# include "fts_key_delete.h"
# include "fts_key_up.h"
# include "fts_key_down.h"
# include "fts_key_right.h"
# include "fts_key_left.h"

void	fts_keys(t_struct *structs);

#endif
