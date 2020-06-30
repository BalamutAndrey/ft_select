/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_structs_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:56:20 by eboris            #+#    #+#             */
/*   Updated: 2020/03/13 15:00:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts_structs_func.h"

t_struct	*fts_structs_create(int argc, char **argv)
{
	t_struct	*structs;

	structs = malloc(sizeof(t_struct));
	structs->args_nb = argc;
	fts_args_write(structs, argc, argv);
	fts_args_max_len(structs);
	return (structs);
}
