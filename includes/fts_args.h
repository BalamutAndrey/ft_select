/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_args.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:14:07 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:04:07 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTS_ARGS_H
# define FTS_ARGS_H

# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include "fts_structs.h"

void	fts_args_write(t_struct *structs, int argc, char **argv);
void	fts_args_del(t_struct *structs, char *name);
void	fts_args_free(t_struct *structs);
void	fts_args_max_len(t_struct *structs);

#endif
