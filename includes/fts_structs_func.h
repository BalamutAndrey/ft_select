/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_structs_func.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:54:28 by eboris            #+#    #+#             */
/*   Updated: 2020/03/11 14:30:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_STRUCTS_FUNC_H
# define FTS_STRUCTS_FUNC_H

# include "fts_structs.h"
# include "fts_term.h"
# include "fts_args.h"

t_struct	*fts_structs_create(int argc, char **argv);

#endif
