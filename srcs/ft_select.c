/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:44:57 by eboris            #+#    #+#             */
/*   Updated: 2020/03/12 14:20:10 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_struct	*g_structs;

int	main(int argc, char **argv, char **env)
{
	t_struct	*structs;

	fts_check_error(argc, env);
	g_structs = fts_structs_create(argc, argv);
	structs = g_structs;
	fts_term_init(structs);
	fts_signal_set();
	fts_args_print(structs);
	fts_keys(structs);
	fts_term_restore(structs);
	return (0);
}
